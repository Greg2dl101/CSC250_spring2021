/*
Program for Assignment 7
Accepts user's name as string, prints it in reverse, states wat array element is
space, and reprints name [Last name], [First name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

//function prototypes
int countChars(char *aPtr);
void reverseString(char *b, int end);
int findSpace(char *c);

int main(void)
{
  //intitialize character array
  char usrName[SIZE];

  //prompt user for name and store in array
  printf("Please enter name:");
  fgets(usrName, SIZE, stdin);

  //calls function to determine length of string
  int len = countChars(usrName);

  //clear newline character
  usrName[len] = '\0';

  //calls function to reverse and print reverse string
  reverseString(usrName, len);

  //calls function to find space in name and sets value to space
  int space = findSpace(usrName);

  //prints last name
  printf("%s ", &usrName[space]);

  //prints first name
  printf("%.*s\n", space, &usrName[0]);


}//end of main function

//function to count characters in array (ask if I can use strlen)!!!
int countChars(char *aPtr)
{
  int len = -1;//initiated at -1 to account for null in count.

  while (*aPtr != '\0')
  {
    ++len;

    ++aPtr;
  }

  printf("There are %d characters in your name!", len - 1);//-1 for space

  //return amout of characters in array -1 to accound for '\0'
  return len;
}//end of function


void reverseString(char *b, int end)
{
  char b2[SIZE];
  int begin, count;

  //initialize count & len;
  count = end;

  printf("Your name in reverse is:\n");

  for (begin = 0; begin <= count; begin++)
  {
    b2[begin] = b[end];
    printf("%c", b2[begin]);
    end--;
  }//end of for loop

  puts("");
}//end of reverseString

//function that searches string for space
int findSpace(char *c)
{
  //declare and initialize counter
  int count = 1;

  while (*c != ' ')
  {
    ++count;

    ++c;
  }

  printf("Space is the element %d in your name!\n", count);

  return count;
}//end of findSpace
