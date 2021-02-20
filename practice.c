/*
Tim Cook has been reviewing complaints from his customers that they are receiving damaged iPhones and suspects that there is a problem with temperature controls at a specific warehouse facilities.  Apple recommends storing the iPhone between -4º to 113º F to avoid damage.  Mr. Cook wants to review average daily temperatures from this facility to determine if there is a problem.  Create a program that allows him to enter 21 temperatures/values then determine the following:

    • Use an array to store the values entered by the user.
    • Create one function that determines and returns the average of the values.
    • Create a function that returns the highest value entered using the array of entered values.
    • Create a function that returns the lowest value entered using the array of entered values.
    • Display the average temperature, the highest temperature and the lowest temperature.  Notify the user if any of the computed values (the average, high or low) is outside of the recommended operating range. Do this for each array.
    • Use whole (integer) values, do not worry about decimal values.


Some reminders:
    • Each temperature entered represents the average temperature for that day.  That is, for each value the program accepts that as an entry for one day.
    • Use Fahrenheit for the acceptable temperature range. You don’t need to worry about validating user input though.  Assume your users will be entering reasonable values.
    • You only need to submit your code file ( temperatures .c).
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 21

//function prototypes
int averageTemp(float b[], int size, int average);
int highTemp(float c[], int size, int high);
int lowTemp(float d[], int size, int low);
void printWarning(int x, int y, int z);

int main(void)
{
  //initialize variables for average, lowest and highest temps
  int averageOfTemp;
  int highestTemp;
  int lowestTemp;

  //int array to store temps
  float temp[SIZE];

  //Prompts user
  printf("Please enter %d numbers:\n", SIZE);

  //for loop to store numbers in array
  for (int i = 0; i < SIZE; i++)
  {
    scanf("%f", &temp[i]);
  }

  //call averageTemp function
  averageOfTemp = averageTemp(temp, SIZE, averageOfTemp);

  //call function and set value of highTemp
  highestTemp = highTemp(temp, SIZE, highestTemp);

  //call function and set value of lowTemp
  lowestTemp = lowTemp(temp, SIZE, lowestTemp);

  printWarning(averageOfTemp, highestTemp, lowestTemp);
}//end of main

//averages the value of numbers in array
int averageTemp(float b[], int size, int average)
{
  //variable thats stores total values of array elements
  float total = 0;

  for (int i = 0; i < size; i++)
  {
    total += b[i];
  }

  average = total / size;

  printf("The average is: %d\n", average);

  return average;
}//end of averageTemp function

//sort array for highest value
int highTemp(float c[], int size, int high)
{
  high = c[0];

  for (int i = 0; i < size; i++)
  {
    if (high < c[i])
    {
      high = c[i];
    }
  }

  printf("The high is: %d\n", high);

  return high;
}

//sort array for lowest value
int lowTemp(float d[], int size, int low)
{
  low = d[0];

  for (int i = 0; i < size; i++)
  {
    if (low > d[i])
    {
      low = d[i];
    }
  }

  printf("The low is: %d\n", low);

  return low;
}//and of lowTemp sort array

void printWarning(int x, int y, int z)
{
  //prints warning if average temp is out of range
  if (x < -4 || x > 113)
  {
    printf("WARNING: The average is outside the recommended range!\n");
  }

  //prints watning if highest temp is out of range
  if (y < -4 || y > 113)
  {
    printf("WARNING: The high is outside the recommended range!\n");
  }

  //prints warning if lowest temp is out of range
  if (z < -4 || z > 113)
  {
    printf("WARNING: The low is outside the recommended range!\n");
  }
}
