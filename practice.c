


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
void printAll(struct file files[], int end);
void printIndex(struct file files[]);
void printOut(struct file files[], int end);
void addRecord(struct file files[], int end);


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
    printf("Unable to open file!\n");
    exit(1);
  }

  //declare variable for array of structs
  struct file files[100];
  int i = 0;
  int end = 0;

  /*
  while(fscanf(ifp, "%s %s %s %s", files[i].cve, files[i].cvss, files[i].date, files[i].software) != EOF)
  {
    i++;
    end++;
  }
  */

  //process user's selection, oops until exit is selected
  do
  {
    while(fscanf(ifp, "%s %s %s %s", files[i].cve, files[i].cvss, files[i].date, files[i].software) != EOF)
    {
      i++;
      end++;
    }

    //user menu
    printf("1.) Print All\n");
    printf("2.) Print Index\n");
    printf("3.) Add Record\n");
    printf("4.) Exit\n");
    scanf("%d", &userChoice);

    switch (userChoice)
    {
      case 1:
      //calls function to print all
      printAll(files, end);
      break;

      case 2:
      //call function that prints individual record
      printIndex(files);
      break;

      case 3:
      //closes file pointer for reading
      fclose(ifp);

      //calls function that adds record
      addRecord(files, end);

      //reopens file in read only mode
      FILE *ifp = fopen("nvdcve.dat", "r");

      //check for successful open
      if(ifp == NULL)
      {
        printf("Unable to open file!\n");
        exit(1);
      }
    }



  } while(userChoice != 4);

  //close file
  fclose(ifp);

  return 0;
}

//function that prints out all records
void printAll(struct file files[], int end)
{
  for(int i = 0; i < end; i++)
  {
    printf("%s %s %s %s\n", files[i].cve, files[i].cvss, files[i].date, files[i].software);
  }
  //puts whitespace after loop
  puts("");

}//end of printAll

//function that prints based on index value
void printIndex(struct file files[])
{
  int record;

  //prompts user
  printf("Which record would you like to print? ");
  scanf("%d", &record);

  printf("%s %s %s %s\n", files[record].cve, files[record].cvss, files[record].date, files[record].software);

}//end of printIndex

//function that opens file in write mode to add new record
void addRecord(struct file files[], int end)
{
  //opens file in write mode and created pointer
  FILE *ifp = fopen("nvdcve.dat", "w");

  //prompts and stores user input
  printf("     CVE: ");
  scanf("%s", files[end].cve);
  printf("    CVSS: ");
  scanf("%s", files[end].cvss);
  printf("    DATE: ");
  scanf("%s", files[end].date);
  printf("SOFTWARE: ");
  scanf("%s", files[end].software);

  fprintf(ifp, "%s %s %s %s\n", files[end].cve, files[end].cvss, files[end].date, files[end].software);

  //close file pointer
  fclose(ifp);
}
