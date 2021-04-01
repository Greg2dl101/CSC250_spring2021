#include <stdio.h>
#include <stdlib.h>

//struct for file
struct cpFile
{
  int x;
};

int main(void)
{
  //creates variable of the new data type
  struct cpFile file, *structPtr;

  //sets pointer to memory location of variable
  structPtr = &file;

  //create pointer to struct and allocates memory
  structPtr = (struct cpFile*)malloc(sizeof (struct cpFile));


  //test for success of malloc
  if(structPtr == NULL)
  {
    printf("Failed to allocate memory!\n");
    exit(0);
  }

  //test function
  //printf("%p\n", &structPtr);

  //takes user input and stores in struct variables
  printf("Enter value for x: ");
  scanf("%d", &(*structPtr).x);

  //test function
  printf("%d\n", (*structPtr).x);

  //deallocate memory
  free(structPtr);

  return 0;
}
