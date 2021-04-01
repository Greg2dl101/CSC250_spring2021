/*
Your job will be to create a program that uses structures. You will create a structure that holds info about a computer file. It must have a character array (up to 100 characters) to hold the name of the file. An integer to hold the size of the file. It must also hold a character to hold the type of file (D for directory and F for file). Finally it must use a long to hold the timestamp of the last time the file was accessed.

Part 1
In your main you should create a pointer to the structure, malloc memory for the structure, and prompt/read in data about your structure. Do NOT print out the file info in the main.

Part 2
Write 1 function that prints out the contents of the file structure. Your function should have 1 parameter which is a pointer to the file structure.

Below shows the expected output of running the program. Your output MUST match exactly the output below for the input from above.
The output of the print function is the last line of the output. There must be 1 newline at the end of the print function.

./a.out
Enter the type:D
Enter the filename:hello
Enter the access time:1234567890
Enter the size:24
Filename hello Size 24 Type[D] Accessed @ 1234567890
*/

/*
  - create structure with char, char array, int and long vars
  - create file of new type and pointer
  - malloc memory for pointer
  - test for memory allocation
  - set pointer to location of new type
  - read in inputs for struct items (clear \n after char types)
  - create function that accepts pointer as a parameter and prints file info
  - free allocated memory in main function
*/

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
  //declare file fariable and ptr for file
  file file1, *aPtr;

  //sets ptr to location of file1
  aPtr = &file1;

  //allocates memory for ptr
  aPtr = (file*)malloc(sizeof(struct file));

  //tests for successful memory alocation
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

  //calls function that prints fine information
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
