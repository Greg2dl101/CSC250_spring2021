//program that tests if user can calculate the product of two random numbers.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//function prototype
int multipliedNums(void);

//main function included in every program
int main(void)
{
  //randomize random number generator using time
  srand(time(NULL));

  //declare variables
  int userGuess, product;
  char choice;

  //loop that asks multiplication questions until user quits
  do
  {
    //stores return value from function into variable
    product = multipliedNums();

    //loop that storees user's answer and tells if they are correct or wrong
    do
    {
      //prompts user for answer
      printf("Your Answer: ");
      scanf("%d", &userGuess);
      //if..else that notifies user if they answered correctly or not
      if (userGuess != product)
      {
        printf("Wrong, please try again!\n");
      }
      else
      {
        printf("Correct! Try another problem!\n");
      }
    } while(product != userGuess);

    //creates whitespace after every iteration
    puts("");

    //stores user's decision to continue or not in choice and restarts loop if y
    printf("Would you like to continue? [y/n]\n");
    scanf(" %c", &choice);

  } while(choice == 'y');

}

//function that generates two numbers, asks user for their product and returns
//actual value
int multipliedNums(void)
{
  int num1 = 1 + (rand() % 9);
  int num2 = 1 + (rand() % 9);

  printf("What is the product of %d and %d? \n", num1, num2);

  return num1 * num2;
}
