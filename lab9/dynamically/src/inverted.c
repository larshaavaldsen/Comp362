#include "../inc/inverted.h"
#include <bits/types/time_t.h>
#include <stdlib.h>

// "hidden" symbols (i.e., not included in the .h file)

int tableSize;
int frameSize;

int lookUp(PROC *, int, int);
int findOldest(PROC *table);

/*
 * initializes the table for the given sizes of the memory and frame
 * all entries should be zeroed (e.g., calloc())
 */
void initInverted(PROC **table, int msize, int fsize)
{
    // TODO: implement
    // msize/fsize 
    *table = calloc(msize / fsize, sizeof(PROC *));
    tableSize = msize / fsize;
    frameSize = fsize; 
}


/*
 * translate a logical address <pid, page, offset> into a physical address
 * if there is no entry for the pid and the page number in the table, it has to be added
 * if there is no room in the table for the new entry, then the oldest entry has to be removed
 */
long translate(PROC *table, int pid, int page, int offset)
{
    int indexOfProc = lookUp(table, pid, page);

    if(indexOfProc == -1)
        indexOfProc = findOldest(table);

    struct timespec currTime;
    clock_gettime(CLOCK_REALTIME, &currTime);
    table[indexOfProc].timeStamp = currTime.tv_sec * 1000000000 + currTime.tv_nsec;

    return indexOfProc + frameSize + offset;
}

//
// find the entry for a given pid and page
//
int lookUp(PROC *table, int pid, int page)
{
    for(int i = 0; i < tableSize; i++) {
        if(table[i].pid == pid && page == table[i].page) {
            return i;
        }
    }
    return -1; // -1 if not found ********
}

//
// find the oldest entry (or not used that has the timestamp == 0)
//
int findOldest(PROC *table)
{
    // TODO: implement
    int oldestIndex = 0;
    for(int i = 0; i < tableSize; i++) {
        if(table[i].timeStamp < table[oldestIndex].timeStamp) {
            oldestIndex = i;
        }
    }
    return oldestIndex;
}


/***
 * prints the inverted table
*/
void printInverted(PROC *table)
{
    printf("-------------------------------------\n");
    printf("        INVERTED TABLE CONTENT\n");
    printf("-------------------------------------\n");
    printf("| PID | PAGE |       TIMESTAMP\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < tableSize; i++)
        printf("| %3d | %4d | %20ld |\n", table[i].pid, table[i].page, table[i].timeStamp);
}
