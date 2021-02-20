//program for assigntment 6 temperatures.c

//standard libraries for programs
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
  //variables for average, lowest and highest temps
  int averageOfTemp;
  int highestTemp;
  int lowestTemp;

  //int array to store temps
  float temp[SIZE];

  //Prompts user
  printf("Please enter %d temperatures:\n", SIZE);

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

  //sums value of all array indexes
  for (int i = 0; i < size; i++)
  {
    total += b[i];
  }

  //calculates average
  average = total / size;

  //prints average
  printf("The average is: %d\n", average);

  return average;
}//end of averageTemp function

//sort array for highest value
int highTemp(float c[], int size, int high)
{
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

//prints warning messages if temps are out of range
void printWarning(int x, int y, int z)
{
  //prints warning if average temp is out of range
  if (x < -4 || x > 113)
  {
    printf("WARNING: The average is outside the recommended range!\n");
  }

  //prints warning if highest temp is out of range
  if (y < -4 || y > 113)
  {
    printf("WARNING: The high is outside the recommended range!\n");
  }

  //prints warning if lowest temp is out of range
  if (z < -4 || z > 113)
  {
    printf("WARNING: The low is outside the recommended range!\n");
  }
}//end of printWarning
