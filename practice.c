#include <stdio.h>
#include <stdlib.h>

struct node
{
  int val;
  struct node *next;
};

struct node *insertFront(int val, struct node *head)
{
  struct node *tmp;
  tmp = malloc(sizeof(struct node));
  tmp->val = val;
  tmp->next = head;
  return tmp;
}

int main()
{
  //create poiners to nodes
  struct node *head = NULL;
  struct node *tmp = NULL;

  head = insertFront(97, head);
  head = insertFront(21, head);
  head = insertFront(31, head);
  head = insertFront(55, head);
  head = insertFront(10, head);

  //loops and prints each value in list
  tmp = head;
  while (tmp != NULL)
  {
    printf("%d\n", tmp->val);
    tmp = tmp->next;
  }

  free(tmp);

  return 0;
}//end of main
