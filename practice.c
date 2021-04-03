


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


//function prototypes
void fileCheck(FILE *ifp);
void printAll(struct file files[], int end);
void printIndex(struct file files[], int end);
void addRecord(struct file files[], int end);

//main function
int main()
{
  //file pointer
  FILE *ifp = fopen("nvdcve.dat", "r");

  //declare variables
  unsigned int userChoice;//for user's menu choice

  //declare variable for array of structs
  struct file files[100];

  //calls function that checks if file was opened successfully
  fileCheck(ifp);

  //process user's selection, loops until exit is selected
  do
  {
    //places cursor at beginning of file
    rewind(ifp);

    //variables to use with while loop that stores file data insto struct
    int i = 0;
    int end = 0;

    //adds data from file to struct array
    while(fscanf(ifp, "%s %s %s %s", files[i].cve, files[i].cvss, files[i].date, files[i].software) != EOF)
    {
      i++;
      end++;
    }

    //menu
    printf("1. Print All\n");
    printf("2. Print Index\n");
    printf("3. Add Record\n");
    printf("4. Exit\n");
    scanf("%d", &userChoice);
    getchar();//clear input buffer

    //runs functions based on user's inuput
    switch (userChoice)
    {
      case 1:
      //calls function to print all
      printAll(files, end);
      break;

      case 2:
      //call function that prints individual record
      printIndex(files, end);
      break;

      case 3:
      //closes file pointer for reading
      fclose(ifp);

      //calls function that adds record
      addRecord(files, end);

      //opens file pointer in read mode
      ifp = fopen("nvdcve.dat", "r");

      //calls function that checks if file was opened successfully
      fileCheck(ifp);

    }

  } while(userChoice != 4);

  //close file
  fclose(ifp);

  return 0;
}

//function that checks o see if file was successfuly opened
void fileCheck(FILE *ifp)
{
  //checks if file was opene
  if(ifp == NULL)
  {
    printf("Unable to open file!\n");
    exit(1);
  }

}//end of fileCheck

//function that prints out all records stored in struct
void printAll(struct file files[], int end)
{
  //prints all records stores in struct
  for(int i = 0; i < end; i++)
  {
    printf("****************************************\n");
    printf("*%3d.%8s: %-12s\n", i, "CVE", files[i].cve);
    printf("*%12s: %-12s\n", "CVSS",files[i].cvss);
    printf("*%12s: %-12s\n", "Date",files[i].date);
    printf("*%12s: %-12s\n", "Software",files[i].software);
    printf("****************************************\n");
  }

  //puts whitespace after loop
  puts("");

}//end of printAll

//function that prints based on index value
void printIndex(struct file files[], int end)
{
  //variable to store user input
  int record;

  //controll loop to check for valid entries
  do
  {
    //prompts user
    printf("Which record would you like to print? ");
    scanf("%d", &record);

  }while (record < 0 || record > end);

  //prints record at the index user selects
  printf("****************************************\n");
  printf("*%3d.%8s: %-12s\n", record, "CVE", files[record].cve);
  printf("*%12s: %-12s\n", "CVSS",files[record].cvss);
  printf("*%12s: %-12s\n", "Date",files[record].date);
  printf("*%12s: %-12s\n", "Software",files[record].software);
  printf("****************************************\n");

  //puts whitespace after loop
  puts("");

}//end of printIndex

//function that opens file in write mode to add new record
void addRecord(struct file files[], int end)
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
  fileCheck(ifp);

  //prints string to file
  fprintf(ifp, "%s\n", newRecord);

  //close file pointer
  fclose(ifp);

}//end of addRecord
