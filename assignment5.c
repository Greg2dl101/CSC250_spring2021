/*
Program for questions 5.53 & 5.54 Asks arithmetic questions based on user input.
*/

#include <stdio.h> //included for standard c library functions
#include <stdlib.h> //included for standard c library functions
#include <time.h> //included for time function to seed number generator

//function prototypes
int calculateArithmetic(int x, int y);
void getComment(int x);

//main function included in every program
int main(void)
{
  //seed random number generator using time
  srand(time(NULL));

  //declare variables
  int userGuess, correctAnswer, evaluation, difficulty, arithmeticChoice;
  char choice;

  //declared and initialized variables
  int count = 10;

  //loop that asks multiplication questions until user quits
  do
  {
    //initializes variable to track total of correct answers
    int amountCorrect = 0;

    //prompts user to select difficuty and stores in var.
    printf("What difficulty would you like to select (1 or 2)? ");
    scanf("%d", &difficulty);

    //prompts user to select type of arithmetic and stores in var.
    printf("What type of probles would you like to solve (1 = addition, 2 = subtraction, 3 = multiplication, 4 =random)? ");
    scanf("%d", &arithmeticChoice);

    //for loop that generates 10 questions and provides feedback
    for (int i = 1; i <= count; i++)
    {
      //stores return value from function into variable
      correctAnswer = calculateArithmetic(difficulty, arithmeticChoice);

      //prompts user for answer and stores in var.
      printf("Your Answer: ");
      scanf("%d", &userGuess);

      //if..else that notifies user if they answered correctly or not
      if (userGuess != correctAnswer)
      {
        getComment(0);//gets comments for wrong answers
      }
      else
      {
        getComment(1);//gets comments for right answers

        amountCorrect++;//increments correctAnswers by 1 for every right answer
      }
      //creates whitespace after every iteration
      puts("");
    }

    //calculates grade
    evaluation = amountCorrect / count;

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

//function that generates two numbers, asks user for their answer and returns
//calculated answer
int calculateArithmetic(int x, int y)
{
  //declared variables
  int num1, num2;

  //stores either single or double digit randomized numbers in variables
  if (x == 1)
  {
    num1 = 1 + (rand() % 9);
    num2 = 1 + (rand() % 9);
  }
  else
  {
    num1 = 1 + (rand() % 99);
    num2 = 1 + (rand() % 99);
  }

  //selection statemets that ask question and return value based on use iput
  if (y == 1)
  {
    printf("What is the sum of %d and %d? \n", num1, num2);

    return num1 + num2;
  }
  else if (y == 2)
  {
    printf("What is the difference of %d and %d? \n", num1, num2);

    return num1 - num2;
  }
  else if (y == 3)
  {
    printf("What is the product of %d and %d? \n", num1, num2);

    return num1 * num2;
  }
  else
  {
    switch (rand() % 3)//asks question based on number generator
    {
      case 0: printf("What is the sum of %d and %d? \n", num1, num2);
      return num1 + num2;
      break;
      case 1: printf("What is the difference of %d and %d? \n", num1, num2);
      return num1 - num2;
      break;
      case 2: printf("What is the product of %d and %d? \n", num1, num2);
      return num1 * num2;
    }
  }

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
