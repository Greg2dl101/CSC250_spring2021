/*
Your job will be to create a program that uses pointers. Your output must be done in the main function and the calculations MUST be done in the three functions. Therefore you MUST use pointers correctly.

You must declare and implement the following 3 functions. Below are the three prototypes that you must use in this program.

void max(int *a, int *b, int *c, int *d, int *result);
void min(int *a, int *b, int *c, int *d, int *result);
void mul(int *a, int *b, int *c, int *d, int *result);

The functions have the following meaning:
max
finds the max value of a,b,c,d and stores the largest value in result.
min
finds the min value of a,b,c,d and stores the largest value in result.
mul
multiplies a * b * c and divides by d. Stores that value in result.

Below is an example input/output. This input will be read in via the keyboard (use
scanf).

input
output (note that user input is shown in bold)
1 2 3 4
Enter the 4 numbers: 1 2 3 4
The max is 4. The min is 1. (a * b * c) / d = 1
100 3 201 103
Enter the 4 numbers: 100 3 201 103
The max is 201. The min is 3. (a * b * c) / d = 585

Your output MUST match exactly the output and the input from above.
You only need to submit your file (pointers.c)
*/

#include <stdio.h>

//function prototypes
void max(int *a, int *b, int *c, int *d, int *result);
void min(int *a, int *b, int *c, int *d, int *result);
void mul(int *a, int *b, int *c, int *d, int *result);

//main function
int main(void)
{
  //declare the variables
  int num1, num2, num3,num4, result;

  //prompt for user inputs, stores input in variables
  printf("Enter the 4 numbers: ");
  scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

  //call max function
  max(&num1, &num2, &num3, &num4, &result);

  //prints max
  printf("The Max is %d. ", result);

  //call min function
  min(&num1, &num2, &num3, &num4, &result);

  //prints min
  printf("The min is %d. ", result);

  //calls mul function
  mul(&num1, &num2, &num3, &num4, &result);

  //prints new result
  printf("(a * b * c) / d = %d\n", result);


  return 0;
}//end main

//function that finds highest value
void max(int *a, int *b, int *c, int *d, int *result)
{
  *result = *a;

  if (*b > *result)
  {
    *result = *b;
  }
  if (*c > *result)
  {
    *result = *c;
  }
  if (*d > *result)
  {
    *result = *d;
  }

}//end of max

//function that finds lowest value
void min(int *a, int *b, int *c, int *d, int *result)
{
  *result = *a;

  if (*b < *result)
  {
    *result = *b;
  }
  if (*c < *result)
  {
    *result = *c;
  }
  if (*d < *result)
  {
    *result = *d;
  }
}//of of min function

//function that inserts variables into an equation
void mul(int *a, int *b, int *c, int *d, int *result)
{
  *result = (*a * *b * *c) / *d;
}//en of mul function
