//practice for Assignment 10

//C libraries needed for progrm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct array to store data from .dat file
struct record
{
  char cve[100];
  char cvss[100];
  char date[100];
  char sw[100];
};

//function prototypes
void checkFile(FILE *ifp);
void printAll(struct record records[], int end);
void printIndex(struct record records[], int end);
void addIndex();

//main function to be included in all programs
int main()
{
  //creates file pointer opens .dat file in read mode
  FILE *ifp = fopen("nvdcve.dat", "r");

  //checks for successful file open
  checkFile(ifp);

  //declare array of records to store data from .dat file
  struct record records[100];

  //declares variable that stores user's user's choice
  int userChoice;

  do
  {
    //places file cursor at beginning of file
    rewind(ifp);

    //declares variables that increment as in while loop
    int i = 0;
    int end = 0;

    while (fscanf(ifp, "%s %s %s %s", records[i].cve, records[i].cvss, records[i].date, records[i].sw) != EOF)
    {
      i++;
      end++;
    }

    //prompts user for menu selection and stores input in variable
    printf("(1.) Print All\n");
    printf("(2.) Print Index\n");
    printf("(3.) Add Record\n");
    printf("(4.) Exit\n");
    scanf("%d", &userChoice);
    getchar();//clear input buffer

    switch (userChoice)
    {
      case 1:
      //calls funcition that prints all records from .dat file
      printAll(records, end);
      break;

      case 2:
      //calls funcition that prints single record from.dat file
      printIndex(records, end);
      break;

      case 3:
      //closes pointer in read mode
      fclose(ifp);

      //calls function that adds record to .dat file
      addIndex();

      //opens file back in read  mode
      ifp = fopen("nvdcve.dat", "r");

      //checks for successful file open
      checkFile(ifp);

    }

  } while(userChoice != 4);

  //closes file
  fclose(ifp);

  return 0;
}//end of main

//function that checks for successful file open. exits program is unsuccessful.
void checkFile(FILE *ifp)
{
  if(ifp == NULL)
  {
    printf("File was not opened!\n");
    exit(1);
  }
}//end of checkFile

//function that prints all records from.dat file
void printAll(struct record records[], int end)
{
  //loops through struct array and prints all records
  for (int i = 0; i < end; i++)
  {
    printf("***********************************\n");
    printf("%3d%9s: %s\n", i, "CVE", records[i].cve);
    printf("%12s: %s\n","CSS", records[i].cvss);
    printf("%12s: %s\n","Date", records[i].date);
    printf("%12s: %s\n","Software", records[i].sw);
    printf("***********************************\n");
  }

  //creates whitespace in output
  puts("");

}//end of printAll

//function that prints a single record based on user's choice
void printIndex(struct record records[], int end)
{
  //variable to store user's user's choice
  int index;

  //control loop to ensure user makes valid entries
  do
  {
    printf("Which record would you like to print? ");
    scanf("%d", &index);
    getchar();

  } while(index < 0 || index > end);

  //prints record after valid entry is made
  printf("***********************************\n");
  printf("%3d%9s: %s\n", index, "CVE", records[index].cve);
  printf("%12s: %s\n","CSS", records[index].cvss);
  printf("%12s: %s\n","Date", records[index].date);
  printf("%12s: %s\n","Software", records[index].sw);
  printf("***********************************\n");

  //creates whitespace in output
  puts("");

}//end of printIndex

//function that opens file in write mode and appends new entry
void addIndex()
{
  //charaacter array to sotore new data
  char newRecord[100];

  //print prompts for user input and stores in array
  printf("Enter CVE, CVSS, Date & Software:\n");
  fgets(newRecord, 100, stdin);
  newRecord[strcspn(newRecord, "\n")] = 0; //clear newline

  //opens file in write mode and created pointer
  FILE *ifp = fopen("nvdcve.dat", "a");

  //calls function that checks if file was opened successfully
  checkFile(ifp);

  //prints string to file
  fprintf(ifp, "%s\n", newRecord);

  //close file pointer
  fclose(ifp);

}//end of addIndex
