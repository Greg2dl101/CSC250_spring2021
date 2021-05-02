/*
In this assignment, you'll be creating a program that reads in several numbers from a file defined via command line argument then calculates the sum, min, max, and then finally sorts the numbers before printing. You may use the sorts we discussed in class or those defined elsewhere but I do ask that you compose your own code for all components (including the sort) and do not copy direct code segments or snippets from online sources or other students.

Your program should provide basic error messaging when a user tries to open a file that doesn't exist.
Example input file:
4
55
1
98
-1
34

Example output on stdout:
./a.out in.txt
Min: -1
Max: 98
Sum: 191
Sorted:
-1 1 4 34 55 98

Example output on stdout with incorrect argument count:
./a.out
Format: ./a.out <filename>
or
./a.out a b c
Format: ./a.out <filename>

Example output on stdout with file that doesn't exist:
./a.out notafile.txt
Unable to open file
*/

//1. create .txt file which numbers
//2. read numbers from .txt file
//3. create error checking to ensure proper file was opened
//4. store numbers into array
//5. sort numbers to find min
//6. sort numbers to find max
//7. add numbers to find sum
//8. sort numbers from east to greatest
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function prototypes
void findMin(int end, int nums[]);
void findMax(int end, int nums[]);
void findSum(int end, int nums[]);
void sortArray(int end, int nums[]);
void printArray(int end, int nums[]);

//main function to incluse in all C prgrams
int main(int argc, char *argv[])
{
  //checks for amount of arguments
  if (argc != 2)
  {
    printf("Invalid entry! Please run program with file.txt\n");
    exit(1);
  }

  //checks if second argument in command line is appropriate .txt file
  if (strcmp(argv[1], "file.txt") != 0)
  {
    printf("Invaled entry! Please use with file.txt!\n");
    exit(1);
  }

  //creates file pointer
  FILE *file = fopen(argv[1], "r");

  //checks if file was successfully opened
  if (file == NULL)
  {
    printf("File not opened!\n");
    exit(1);
  }

  int i = 0;//counter variable
  int nums[100];//array to store numbers fom .txt file

  //stores each .txt line into array element
  while (fscanf(file, "%d", &nums[i]) != EOF)
  {
    i++;
  }

  //closes file
  fclose(file);

  //calls function that checks for smallest number
  findMin(i, nums);

  //calls function that checks for largest number
  findMax(i, nums);

  //calls function that finds sum of all numbers in array
  findSum(i, nums);

  //calls function that sorts array from smallest to largest
  sortArray(i, nums);

  //calls function that prints sortarray
  printArray(i, nums);

  return 0;
}

//function that finds smallest number in array and prints number
void findMin(int end, int nums[])
{

  int min = nums[0];//declare and initialize min var

  for (int i = 0; i < end; i++)
  {
    if (min > nums[i])
    {
      min = nums[i];
    }
  }

  printf("Min: %d\n", min);

}//end of findMin

//function that finds largest number in array and prints number
void findMax(int end, int nums[])
{
  int max = nums[0];//declare and initialize max var

  for (int i = 0; i < end; i++)
  {
    if (max < nums[i])
    {
      max = nums[i];
    }
  }

  printf("Max: %d\n", max);

}//end of findMin function

//function that adds all numbers stored in array
void findSum(int end, int nums[])
{
  int sum = 0;//intitialize sum var

  //loop that stores each val in each arr element into sum variable
  for (int i = 0; i < end; i++)
  {
    sum = nums[i] + sum;
  }

  printf("Sum: %d\n", sum);

}//end of findSum function

//function that sorts and prints array
void sortArray(int end, int nums[])
{
  //loop for each element
  for (int i = 0; i < end - 1; i++)
  {
    //loop to compare each element
    for (int j = 0; j < end - i - 1; j++)
    {
      //compare elements
      if (nums[j] > nums[j+1])
      {
        int tmp = nums[j];//stores value of current element in tmp
        nums[j] = nums[j+1];//replace value of current element with one to right
        nums[j+1] = tmp;//stores higher number of two in elemnt to the right
      }
    }
  }

}//end of sortArray function

//function that prints array
void printArray(int end, int nums[])
{
  printf("Sorted:\n");

  //loop to print array
  for (int i = 0; i < end; i++)
  {
    printf("%d ", nums[i]);
  }

  //creates whitespace in output
  puts("");

}//end of printArray function
