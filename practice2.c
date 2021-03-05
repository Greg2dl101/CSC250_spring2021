/*
Part 1
In your main() function, asks the user to enter their full name. Ensure that you can successfully store their name in a single character array, with the space. Ensure you do not have a rogue ‘\n’ character in the array. Make sure that you can handle a reasonable name. There’s a good chance that I won’t grade the assignment based upon your name .
Part 2
Pass a pointer of your character array into a function that outputs the number of characters stored in your character array. This function will need to also return this integer back to your main function. You’ll need this value later.
Part 3
Pass a pointer of your character array into a function this displays the reverse. For example, my name of Barbara Myers would be output as: sreyM arabraB
Part 4
Again, passing a pointer to your array, inform the user which character is the space in your name. For example, for Josh Stroschein, my function would output: 4, since the 5th element of my array would be the space (remember element vs element number). This function will need to also return this integer back to your main function. You’ll need this value later.
Part 5
Within your main function, after you’ve called the other functions, reverse your name. For example, my name would be outputted as: Myers Barbara
*/

#include <stdio.h>
#include <stdio.h>

#define SIZE 100

//function prototypes
int countChars(char *aPtr);
void reverseString(char *bPtr, int end);

int main(void)
{
  //initialize character array
  char usrName[SIZE];

  //prompts user for name thn stores in array using fgets
  printf("Please input your name: ");
  fgets(usrName, SIZE, stdin);

  //calls function and stores return value in variable
  int len = countChars(usrName);

  //replaces \n in string with NULL character
  usrName[len] = '\0';

  //calls function that reverses name
  reverseName(usrName, len);






  return 0;
}//end of main

//function that count characters in array
int countChars(char *aPtr)
{
  //declare and initialize counter variable -1 to account for NULL character
  int count = -1;

  //loop that increments counter var until it reaches end of array
  while (*aPtr != '\0')
  {
    ++aPtr;

    ++count;
  }

  printf("There are %d characters in your name!\n", count);

  //returns amount of characters in array, subtract 1 to account for NULL char
  return count;
}//end of countChars

//function that reverses name
void reverseString(char *bPtr, int end)
{
  //declare char array
  char b[];
  int begin, count;

  //sets count to the same length as array
  count = end;


  for (begin = 0; end < count; begin++)
  {
    /* code */
  }


}//end of reverseName
