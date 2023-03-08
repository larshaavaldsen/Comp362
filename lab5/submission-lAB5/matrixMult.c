/*
By Lars Haavaldsen
Comp 362 Lab 2023
*/

#include "matrixMult.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
   if (freopen(argv[1], "r", stdin) == 0)
      oops("Cannot open the input file.\n", -1);

   int **a1, **b1, **c1, **a2, **b2, **c2; // matrices
   int m1, k1, n1, m2, k2, n2; // dimensions of the matices m x k and k x n
   

   allocateAndLoadMatrices(&a1, &b1, &c1, &m1, &k1, &n1);
   allocateAndLoadMatrices(&a2, &b2, &c2, &m2, &k2, &n2);

   // the real magic happens in there

   pthread_t **tids1 = multiply(a1, b1, c1, m1, k1, n1);
   pthread_t **tids2 = multiply(a2, b2, c2, m2, k2, n2);
   join(tids1, m1, n1);
   join(tids2, m2, n2);

   // dispaly results of matrix multiplication

   printf("\nMATRIX A1\n");
   displayMatrix(a1, m1, k1);
   freeMatrix(a1, m1);
   printf("\nMATRIX B1\n");
   displayMatrix(b1, k1, n1);
   freeMatrix(b1, k1);
   printf("\nMATRIX A1 x B1\n");
   displayMatrix(c1, m1, n1);
   freeMatrix(c1, m1);

   printf("\nMATRIX A2\n");
   displayMatrix(a2, m2, k2);
   freeMatrix(a2, m2);
   printf("\nMATRIX B2\n");
   displayMatrix(b2, k2, n2);
   freeMatrix(b2, k2);
   printf("\nMATRIX A2 x B2\n");
   displayMatrix(c2, m2, n2);
   freeMatrix(c2, m2);
   
   // free tids
   free_tids(tids1, k1);
   free_tids(tids2, k2);

   return 0;
}

void *matrixThread(void *param)
{
   // map the parameter onto the structure
   MATRIX_CELL *cell = (MATRIX_CELL *)param;

   // get/add values for cell
   for(int i = 0; i < cell->k; i++) {
      cell->c[cell->i][cell->j] += cell->a[cell->i][i] * (cell->b[i][cell->j]);
   }

   free(cell);

   return NULL;
}

void allocateAndLoadMatrices(int ***a, int ***b, int ***c, int *m, int *k, int *n)
// takes pointers to two-dimensional matrices, so they can be allocated in here
// and used by the caller
{
   if (scanf("%d %d %d", m, k, n) == 0)
      oops("Cannot read matrix sizes.\n", -2);
   
   // allocating m dimension of m x n
   *a = malloc((*m) * sizeof(int *));
   *b = malloc((*k) * sizeof(int *));
   *c = malloc((*m) * sizeof(int *));

   // for each m, allocate out n
   for (int i = 0; i < *m; i++) { 
      (*a)[i] = malloc((*k) * sizeof(int));
   }
   for (int i = 0; i < *k; i++) { 
      (*b)[i] = malloc((*n) * sizeof(int));
   }
   for (int i = 0; i < *m; i++) {
      (*c)[i] = malloc((*n) * sizeof(int));
   }
   
   // load in two matracies from user
   loadMatrix(a, *m, *k);
   loadMatrix(b, *k, *n);
}

void loadMatrix(int ***matrix, int m, int n)
{
   // scan in each value of m, n
   for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
         int num;
         scanf("%d", &num);
         (*matrix)[i][j] = num;
      }
   }
}

void freeMatrix(int **matrix, int m)
{  
   // same steps for allocating, just reverse
   for (int i = 0; i < m; i++) { 
      free((matrix)[i]); 
   }
   free(matrix);
}

pthread_t **multiply(int **a, int **b, int **c, int m, int k, int n)
{
   pthread_t **tids = alloc_tids(m, n);
   // create the threads
   for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++){
         MATRIX_CELL* cell = (MATRIX_CELL*)malloc(sizeof(MATRIX_CELL));
         cell->a = a;
         cell->b = b;
         cell->c = c;
         cell->k = k;
         cell->i = i;
         cell->j = j;
         if(pthread_create(&tids[i][j], NULL, matrixThread, (void *) cell) != 0){
            oops("Couldn't create a thread", 1);
         }
      }
   }
   

   return tids;
}

pthread_t **alloc_tids(int m, int n)
{
   pthread_t **tids;
   // M of tids 
   tids = malloc(m * sizeof(pthread_t));

   // n of tids
   for(int i = 0; i < m; i++) {
      tids[i] = malloc(n * sizeof(pthread_t));
   }

   return tids;
}

void free_tids(pthread_t **tids, int m)
{
   for (int i = 0; i < m; i++) { 
      free((tids)[i]); 
   }
   free(tids);
}

void join(pthread_t **tids, int m, int n)
{
   for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++){
         pthread_join(tids[i][j], NULL);
      }}
}

void displayMatrix(int **matrix, int m, int n)
{
   for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
         printf(" %d ",(matrix)[i][j]);
      }
      printf("\n");
   }
}
