//Program that calculates fair tax

#include <stdio.h>

int main(void)
{
  //variables to store user input
  int housing, food, clothing, transportation, education, healthCare, vacation;

  //variable to store total expenses
  int totalAfterTax = 0;

  //variable to store fair tax
  float fairTax = .3;

  //prompts user inputs then stores them in appropriate variables
  printf("Enter housing expenses: ");
  scanf("%d", &housing);
  printf("Enter food expenses: ");
  scanf("%d", &food);
  printf("Enter clothing expenses: ");
  scanf("%d", &clothing);
  printf("Enter transportation expenses: ");
  scanf("%d", &transportation);
  printf("Enter education expenses: ");
  scanf("%d", &education);
  printf("Enter health care expenses: ");
  scanf("%d", &healthCare);
  printf("Enter vacation expenses: ");
  scanf("%d", &vacation);

  //calculates total amount of taxes
  totalAfterTax = (housing+food+clothing+transportation+education+healthCare+vacation) * fairTax;

  //prints total estimated fair tax user would pay
  printf("Estimated fair tax: $%.2d", totalAfterTax);

}
