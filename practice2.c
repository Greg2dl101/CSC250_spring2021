//accept user input and store into 10 variables
//create linked list
//create function that prints linked list
//create function that reverses linked list
//print reversed linked list


#include <stdio.h>
#include <stdlib.h>

//self-referencing struct
struct node
{
  char val;
  struct node *next;
};

//inserts node between node and NULL
struct node *insertFront(char val, struct node *head)
{
  struct node *tmp;
  tmp = malloc(sizeof(struct node));
  tmp->val = val;
  tmp->next = head;
  return tmp;

  //frees allocated memory
  free(tmp);
}

//function that prints list
void printList(struct node *head)
{
  struct node *tmp = head;

  //prints address of node head is pointing to
  printf("The list is: (Root: %p)\n", &head->next);

  while (tmp != NULL)
  {
    printf("%c --> ", tmp->val);
    tmp = tmp->next;

    if (tmp == NULL)
    {
      printf("NULL\n");
    }
  }
}

//function that reverses linked list
struct node *reverse(struct node *head)
{
  //initializes three nodes used to reverse linked list
  struct node *prev = NULL;
  struct node *current = head;
  struct node *next = NULL;

  //loop that changes the addresses that each node points to
  while(current != NULL)
  {
    next = current->next;

    current->next = prev;

    prev = current;
    current = next;
  }
  return prev;
}

int main()
{
  //variables to store user input
  char c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;

  //prompt for user input
  printf("Enter 10 characters seperated by a space:\n");
  scanf("%c %c %c %c %c %c %c %c %c %c", &c10, &c9, &c8, &c7, &c6, &c5, &c4, &c3, &c2, &c1);

  //create poiners to nodes
  struct node *head = NULL;

  //adds each node so the front of the list
  head = insertFront(c1, head);
  head = insertFront(c2, head);
  head = insertFront(c3, head);
  head = insertFront(c4, head);
  head = insertFront(c5, head);
  head = insertFront(c6, head);
  head = insertFront(c7, head);
  head = insertFront(c8, head);
  head = insertFront(c9, head);
  head = insertFront(c10, head);

  //calls function that prints list
  printList(head);

  //calls function that ressigns the pointing address of "head" to last node in
  //linked list
  head = reverse(head);

  //calls function that prints reversed list
  printList(head);

  //returns 0 of program successfully executed.
  return 0;
}//end of main
