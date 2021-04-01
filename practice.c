#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct to store strings in
struct file
{
  char cve[50];
  char cvss[50];
  char date[50];
  char software[50];
};

//main function
int main()
{
  //file pointer
  FILE *ifp = fopen("nvdcve.dat", "r");

  //declare variables
  unsigned int userChoice;//for user's menu choice

  //check for successful open
  if(ifp == NULL)
  {
    printf("Unable to open file!\n", );
    exit(1);
  }

  //process user's selection, oops until exit is selected
  do
  {
    //user menu
    printf("1.) Print All\n");
    printf("2.) Print Index\n");
    printf("3.) Add Record\n");
    printf("4.) Print Exit\n");
    scanf("%d", &userChoice);

    //declare variable for array of structs
    struct file files[100];
    int i = 0;



  } while(userChoice != 4);

  //close file
  fclose(ifp);

  return 0;
}
