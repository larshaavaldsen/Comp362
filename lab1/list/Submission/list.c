#include "list.h"

void allocate_list(LIST **list, int count)
{
   if (count == 0)
   {
      list = NULL;
      return;
   }

   *list = (LIST*)malloc(sizeof(LIST));
   allocate_list(&((*list)->next), --count);
}

void free_list_iter(LIST *head)
{
   while (head != NULL)
   {
      LIST *next = head->next;
      if (head->data != NULL)
         free(head->data);

      head = NULL;
      free(head);
      head = next;
   }
}

void free_list_emb(LIST *head)
{
   LIST *curr = head;

   if (curr->next)
      free_list_emb(curr->next);

   if (head->data != NULL)
      free(curr->data);
   curr = NULL; 
   free(curr);
}

void free_list_tail(LIST *head)
{
   if (head == NULL)
      return;

   LIST *next = head->next;

   if (head->data != NULL)
      free(head->data);

   head = NULL;
   free(head);

   free_list_tail(next);
}