//interest calculator
#include <stdio.h>
#include <stdbool.h>

//main function
int main(void)
{
  //var for days
  int d;
  // var for interest, principal, and
  float i, r, p;

  //loop that calculates interest based on inputs until cancelled
  while(true)
  {
    //prompts user then stores principal
    printf("Enter loan principal (enter -1 to end): ");
    scanf("%f", &p);

    //statement to break loop if -1 is entered
    if(p == -1)
    {
        return 0;
    }

    //promps user then stores interest rate
    printf("Enter interest rate: ");
    scanf("%f", &r);
    //prompts user then stores loan duration in days
    printf("Enter term of the loan in days: ");
    scanf("%d", &d);

    i = p * r * d/365;//calculates interest

    printf("The interest charge is $%.2f\n", i);//prints interest

    puts(""); //whitespace at end of each iteration

  }//end loop

}

//Why did new line characters ruin the program?
