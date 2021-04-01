//this is my submission for assignment 9, a program that uses a struct to store
//user input and use that information to print out file information.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct for file info
typedef struct file
{
  char type;
  char name[100];
  long accessTime;
  int  size;
} file;

//function prototype
void printFile(file *ptr);

//main function
int main(void)
{
  //declare file variable and ptr for file
  file file1, *aPtr;

  //sets ptr to location of file1
  aPtr = &file1;

  //allocates memory for ptr
  aPtr = (file*)malloc(sizeof(struct file));

  //tests for successful memory alocation, exits program if unsuccessful
  if (aPtr == NULL)
  {
    printf("Failed to allocate memory!");
    exit(0);
  }

  //reads in user inputs
  printf("Enter the type: ");
  scanf(" %c", &(*aPtr).type);
  getchar();//clear input buffer
  printf("Enter file name: ");
  fgets((*aPtr).name, 100, stdin);
  (*aPtr).name[strcspn((*aPtr).name, "\n")] = 0;//clear input buffer
  printf("Enter the access time: ");
  scanf(" %li", &(*aPtr).accessTime);
  printf("Enter the size: ");
  scanf(" %d", &(*aPtr).size);

  //calls function that prints file information
  printFile(aPtr);

  //frees allocated memory
  free(aPtr);

  //return 0 if program executes successfully
  return 0;
}//end of main

//function that prints out file information
void printFile(file *ptr)
{
  printf("Filename %s Size %d Type [%c] Accessed @ %li\n", (*ptr).name, (*ptr).size, (*ptr).type, (*ptr).accessTime);
}//end of printFile
