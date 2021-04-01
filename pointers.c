//This is my program that finds the largest and smallest of 4 numbers input by
//user using pointrs. Also uses those 4 numbers with a simple formula and
//producses and output using pointers.

//libraries to include in program
#include <stdio.h>

//function prototypes requires for program
void max(int *a, int *b, int *c, int *d, int *result);
void min(int *a, int *b, int *c, int *d, int *result);
void mul(int *a, int *b, int *c, int *d, int *result);

//main function included in every program
int main(void)
{
  //declare variables
  int num1, num2, num3, num4, result;

  //takes user inputs and stores into 4 variables
  printf("Enter the 4 numbers: ");
  scanf("%d%d%d%d", &num1, &num2, &num3, &num4);

  //call max function
  max(&num1, &num2, &num3, &num4, &result);

  //prints value of result after passing through max
  printf("The Max is %d. ", result);

  //call min function
  min(&num1, &num2, &num3, &num4, &result);

  //prints value of result after passing through min
  printf("The Min is %d. ", result);

  //call mul function
  mul(&num1, &num2, &num3, &num4, &result);

  //prints value of result after passing through mul
  printf("(a * b * c) / d = %d\n", result);

  return 0;
}

//function that finds largest numbers
void max(int *a, int *b, int *c, int *d, int *result)
{
  //initialize result
  *result = *a;

  //if statements to store largest value at *result
  if (*result < *b)
  {
    *result = *b;
  }
  if (*result < *c)
  {
    *result = *c;
  }
  if (*result < *d)
  {
    *result = *d;
  }
}//end of max function

//funtion that finds smallest number
void min(int *a, int *b, int *c, int *d, int *result)
{
  //initialize result
  *result = *a;

  //if statements to store largest value at *result
  if (*result > *b)
  {
    *result = *b;
  }
  if (*result > *c)
  {
    *result = *c;
  }
  if (*result > *d)
  {
    *result = *d;
  }
}//and of min

//function that calculates (a*b*c)/d
void mul(int *a, int *b, int *c, int *d, int *result)
{
  *result = (*a * *b * *c) / *d;
}//end of mul function
