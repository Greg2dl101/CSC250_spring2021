//Program for questions 5.51 & 5.52
//Program that generates 10 questions and provides feedback for correct and
//incorrect answers based on a number generator Also provides feedback based on
//whether or not the user scores at least a 75%.

#include <stdio.h> //included for standard c library functions
#include <stdlib.h> //included for standard c library functions
#include <time.h>

//function prototypes
int multipliedNums(void);
void getComment(int x);

//main function included in every program
int main(void)
{
  //randomize random number generator using time
  srand(time(NULL));

  //declare variables
  int userGuess, product, evaluation;
  //declared and initialized variables
  int count = 10;
  int correctAnswers = 0;
  //character variable
  char choice;

  //loop that asks multiplication questions until user quits
  do
  {
    //for loop that generates 10 questions and provides feedback
    for (int i = 1; i <= count; i++)
    {

      //stores return value from function into variable
      product = multipliedNums();

      //prompts user for answer
      printf("Your Answer: ");
      scanf("%d", &userGuess);
      //if..else that notifies user if they answered correctly or not
      if (userGuess != product)
      {
        getComment(0);//gets comments for wrong answers
      }
      else
      {
        getComment(1);//gets comments for right answers
        correctAnswers++;//increments correctAnswers by 1 for every right answer
      }
      //creates whitespace after every iteration
      puts("");
    }

    evaluation = correctAnswers / count;//calculates grade

    //provides passing statement of used scores at least 75% and failing
    //statement if user gets lower than 75%.
    if (evaluation >= .75)
    {
      printf("Congratulations, you are ready to go to the next level!\n");
    }
    else
    {
      printf("Please ask your teacher for extra help.\n");
    }

    //creates whitespace in output
    puts("");

    //stores user's decision to continue or not in choice and restarts loop if y
    printf("Would you like to reset for the next student? [y/n]\n");
    scanf(" %c", &choice);

    //creates whitespace in output
    puts("");

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

//function that generates response depending on answer
void getComment(int x)
{
  //generates 1 of 4 comments for correct answer
  if(x == 1)
  {
    switch (rand() % 4)
    {
      case 0: printf("Very good!\n");
      break;
      case 1: printf("Excellent!\n");
      break;
      case 2: printf("Nice work!\n");
      break;
      case 3: printf("Keep up the good work!\n");
    }
  }
  //generates 1 of 4 comment for incorrect answer
  else
  {
    switch (rand() % 4)
    {
      case 0: printf("No. Please try again\n");
      break;
      case 1: printf("Wrong. Try once more.\n");
      break;
      case 2: printf("Don't give up!\n");
      break;
      case 3: printf("No. Keep trying.\n");
    }
  }
}
