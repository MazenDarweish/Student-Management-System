#include<stdio.h>
//To use the function of the strings
#include<string.h>
//Declare the struct and its Variables.
typedef struct 
{
    char gender;
    float GPA;
    char id[8];
    int AcademicYear;
    char name[50];
}student;
//Initialize number of students and give some values.
//Globalize the struct because its is used by all the functions.
student students[50]=
{{.gender='M',.GPA=3.4,.id="2020100",.AcademicYear=4,.name="Mazen Ahmed"},
{.gender='f',.GPA=3.9,.id="2021100",.AcademicYear=3,.name="Reem Raouf"},
{.gender='M',.GPA=2.6,.id="2022100",.AcademicYear=1,.name="Mohamed osama"},
{.gender='f',.GPA=2.8,.id="2023100",.AcademicYear=5,.name="Mariam Mohamed"}};
//Declare a struct named garbage to put in it the deleted students data to use it in reurning data.
student garbage[50];
//Globalize number of students because its used in all the functions.
int StudentNum=4;
//Make a function to print the whole array.
void prtstr()
{
    printf("Num\tName\tID\tGPA\tAcademic Year\tGender\n");
        for(int i=0;i<StudentNum;i++)
        {
            //check if Students data is removed or not.
            if(strlen(students[i].id)==7) 
            {
                printf("%d\t",i+1);
                printf("%s",students[i].name);
                printf("\t%s",students[i].id);
                printf("\t%.2f",students[i].GPA);
                printf("\t%d",students[i].AcademicYear);
                printf("\t%c\n",students[i].gender);
            }
            //when the students data is removed print this sentence.
           else if (strlen(students[i].id)==1)
            {
                printf("%d\t",i+1);
                printf("****Student data has been removed***\n");
            }
        }
}
void AddStudent()
{
    int checkid=0;
    char cont='1';
    int NameSpace=0;
    int wrongid=0;
    
    while (cont=='1')
    {
        //Reset the values to zero every Loop.
       NameSpace=0;
       checkid=0;
    puts("Please enter the Students Name  ");
    gets(students[StudentNum].name);
    gets(students[StudentNum].name);
    //Loop to check for the spaces in the name
    for(int i =0 ; i<50 ; i++)
    {
    if(students[StudentNum].name[i]==' ')
    {
        NameSpace++;
    }
    }
    //if spaces is more than one that means the user entered more than two names.
    if(NameSpace > 1)
    {
        printf("Please Enter the First and the Last Name Only\n");
    
        break;
    }
    //if spaces is less than or equal one means that the student entered only first name.
    else if (NameSpace < 1)
    {
        printf("Please Enter the First and the Last Name\n");
     
        break;
    }
        printf("Please enter student's ID\n");
        scanf(" %s",students[StudentNum].id);
        //Loop to check if the id is repeated or not.
        for(int i =0;i<StudentNum;i++)
        {
            //Compare the id with the previous id's.
            checkid=strcmp(students[StudentNum].id,students[i].id);
            if(checkid==0)
            {
                printf("There is a Student with this ID\n");
                break;
            }
            //Compare the id with the id's in the garbage.
            checkid=strcmp(students[StudentNum].id,garbage[i].id);
            if(checkid==0)
            {
                printf("There is a Removed Student with this ID\n");
                break;
            }
        }
        if (checkid==0)
        {
            break;
        }
        //Check if the id is 7 didgits length.
        if (strlen(students[StudentNum].id) != 7)
        {
            printf("The ID should contain 7 Numbers\n");
            checkid=0;
        }
        if (checkid==0)
        {
            break;
        }
        printf("Please enter Sudent's Academic Year\n");
        scanf("%d",&students[StudentNum].AcademicYear);
        //Check if the Academic Year between 1 and 5.
        if(students[StudentNum].AcademicYear>5 || students[StudentNum].AcademicYear<1)
        {
            printf("Error !! Student Year must be Between 1 and 5\n");
            break;
        }
        printf("Please enter Student's GPA\n");
        scanf("%f",&students[StudentNum].GPA);
        //Check if GPA between 0 and 4.
        if(students[StudentNum].GPA<0 || students[StudentNum].GPA >4)
        {
            printf("Error !! Student's GPA must be Betweeen 0 and 4\n");
            break;
        }
        printf("Please enter the gender of the Student M or F \n");
        scanf(" %c",&students[StudentNum].gender);
        //Check if the user entered M or F lower and upper case.
        if(students[StudentNum].gender != 'm' && students[StudentNum].gender != 'M' && students[StudentNum].gender != 'f' && students[StudentNum].gender != 'F')
        {
           printf("Error !! Student's Gender must be M of F\n");  
           break;
        }

        //Increment the number of students by 1.
   StudentNum++;
    printf("Please enter 1 to continue Adding students and any other key to exit to the main menu\n");
    scanf(" %c",&cont);
    
    }
    prtstr();
}
void RemoveStudent()
{
  char RemoveID[8];
  int RemoveIndex=51;
  int found;
  printf("Please enter the ID of the student\n");
  scanf(" %s",RemoveID);
  //Check for id length.
  if(strlen(RemoveID)!=7)
  {
    printf("Invalid ID\n");
  }
  //If the length is valid search for it in the array.
  else
  {
    for(int i=0;i<StudentNum;i++)
 
   {
      found=strcmp(RemoveID,students[i].id);
        if(found==0)
      {
        //save the index of the id to be removed.
          RemoveIndex=i;
          break;
      }
    }
     if(found==0)
    {
        //Store the Data of this students in case the user needed to return it.
        strcpy(garbage[RemoveIndex].name,students[RemoveIndex].name);
        strcpy(garbage[RemoveIndex].id,students[RemoveIndex].id);
        garbage[RemoveIndex].gender=students[RemoveIndex].gender;
        garbage[RemoveIndex].AcademicYear=students[RemoveIndex].AcademicYear;
        garbage[RemoveIndex].GPA=students[RemoveIndex].GPA;
        //Remove the Data of this student.
        strcpy(students[RemoveIndex].name,".");
        strcpy(students[RemoveIndex].id,"0");
        students[RemoveIndex].AcademicYear=0;
        students[RemoveIndex].GPA=0;
        students[RemoveIndex].gender='.';
        printf("Operation Successful\n");
    }
    //if the result of the string compare not 0 means that there is no student with this id.
    else if(found !=0)
    {
      printf("ID not Found\n");
    }
    }
   
    prtstr();
}
void RetriveStudent()
{
  int  SearchMethod,NameSpace=0,StudentIndex,found,checkid=0;
  char StudentName[50],StudentID[8];
  //Ask the user fo the searching method.
  printf("Please enter 1 to search with name and 2 to search with ID\n");
  scanf("%d",&SearchMethod);
  
      if(SearchMethod==1)
      {
          puts("Please enter student's name ");
          gets(StudentName);
          gets(StudentName);
          for (int i=0;i<50;i++)
          {
            //Check if the user entered a valid name.
              if(StudentName[i]==' ')
              {
                  NameSpace++;
              }
          }
           
              if(NameSpace < 1)
              {
                  printf("Please enter the first and the last name\n");
                 
              }
              else if (NameSpace > 1)
              {
                  printf("Please enter the last and first Name Only\n");
              }
              //If the user entered a valid name execute the operation.
              else
              {
                  for(int j=0;j<StudentNum;j++)
                  {
                    //Search for the entered name in the array of students.
                  found=strcmp(StudentName,students[j].name);
                  if(found==0)
                  {
                    // save the index of the student.
                      StudentIndex=j;
                      break;
                      
                  }
                  
                  }
                  if(found==0)
                  {
                    //print the students data.
                          printf("Name\t\tID\tGPA\tAcademicYear\tGender\n");
                          printf("%s",students[StudentIndex].name);
                          printf("\t%s",students[StudentIndex].id);
                          printf("\t%.2f",students[StudentIndex].GPA);
                          printf("\t%d",students[StudentIndex].AcademicYear);
                          printf("\t%c\n",students[StudentIndex].gender);
                  }
                  else
                  {
                      printf("Student Name Not Found\n");
                  }
              }
      }
      if(SearchMethod==2)
      {
        printf("Please enter Student's ID\n");
        scanf(" %s",&StudentID);
        //Search for the id.
        for(int i=0 ; i<StudentNum ;i++)
        { 
        found=strcmp(StudentID,students[i].id);
            if(found==0)
        {
          StudentIndex=i;
          break;
        }
        }
        if(found==0)
        {
            //print the students data matched with the entered id.
           printf("Name\t\tID\tGPA\tAcademicYear\tGender\n");
                          printf("%s",students[StudentIndex].name);
                          printf("\t%s",students[StudentIndex].id);
                          printf("\t%.2f",students[StudentIndex].GPA);
                          printf("\t%d",students[StudentIndex].AcademicYear);
                          printf("\t%c\n",students[StudentIndex].gender);                   
        }
        //Error message for the length
        else if (strlen(StudentID) != 7)
        {
            printf("The ID should contain 7 Numbers\n");    
        }
        }
        //Error message if the user didnt enter a valid number.
        else if (SearchMethod != 1 && SearchMethod != 2)
        {
        printf("Wrong Input\n");
        }
        //If found not equal zero means that the user entered a wrong id.
        else if (found !=0)
        {
            printf("ID not Found\n");
        }
}
void UpdateData()
{
  char SearchID[8];
  int StudentIndex,found=1,UpdateChoice,Error=0;
  printf("Please Enter Students ID\n");
  scanf(" %s",&SearchID);
  //Check for id length.
  if(strlen(SearchID)!=7)
  {
    printf("Invalid ID\n");
  }
  else
  {
  for(int i=0;i<StudentNum;i++)
  {
    //Compare the entered id with the data in the array.
      found=strcmp(students[i].id,SearchID);
      if (found==0)
      {
        //save the index to edit on it.
          StudentIndex=i;
          break;
      }
  }
  if(found==0)
  {
    // Ask for the Variable needed to be updated.
      printf("Please enter 1 to Update the GPA and 2 to Update the Academic Year\n");
      scanf("%d",&UpdateChoice);
      if(UpdateChoice==1)
      {
          printf("Please enter the New GPA\n");
          //Get the new GPA.
          scanf("%f",&students[StudentIndex].GPA);
          //Check if the GPA entered between 0 and 4.
          if(students[StudentIndex].GPA<0 || students[StudentIndex].GPA >4)
        {
            printf("Error !! Student's GPA must be Betweeen 0 and 4\n");
            //Increment Value of error.
            Error++;
        }
      }
      else if(UpdateChoice==2)
      {
        //Check if the student is in the last year.
          if(students[StudentIndex].AcademicYear==5)
          {
            //Cant be updated.
              printf("The student is in Year 5\n");
          }
          else
          //Increment the value of the academic year.
          students[StudentIndex].AcademicYear++;
      }
      //if the user didnt entered the needed value ( 1 or 2 )
      else
      {
          printf("Invalid Input\n");
      }
  }
      else
      {
          printf("ID Not Found\n");
      }
      //If the error still equal zero print the updated array.
      if(Error==0)
      {
        prtstr();
  
      }
      //Error happened while updating the data.
      else
      {
      printf("Students New Data has error\n");
      }
  }
}
void ReturnData()
{
    char studentid[8];
    int found,StudentIndex;
    printf("Please enter Removed student ID\n");
    scanf(" %s",studentid);
    //Check for ID's Length.
    if(strlen(studentid)!=7)
    {
        printf("Invalid ID\n");
    }
    else
    {
        //Search for the entered ID.
    for(int i=0 ;i<StudentNum;i++)
    {
        //compare between the entered ID and the ID that is Removed before.
        found=strcmp(studentid,garbage[i].id);
        if(found==0)
        {
            //If the id found save the index of the data.
            StudentIndex=i;
            break;
        }
    }
    if(found==0)
    {
        //Return the Data to the array.
        strcpy(students[StudentIndex].name,garbage[StudentIndex].name);
        strcpy(students[StudentIndex].id,garbage[StudentIndex].id);
        students[StudentIndex].gender=garbage[StudentIndex].gender;
        students[StudentIndex].AcademicYear=garbage[StudentIndex].AcademicYear;
        students[StudentIndex].GPA=garbage[StudentIndex].GPA;
        //Print the array.
        printf("Operation Successful\n");
        prtstr();
    }
    else if(found!=0)
    {
        //ID not found in the garbage array.
        printf("ID not found\n");
    }
    }
}
int main()
{
    int  oper;
    char cont[2]='1';
    char password[10],password1[10];
    char username[10],username1[10];
    //Initialize the values of the Username and password.
    strcpy(username,"Admin123");
    strcpy(password,"Login123");
    //Loop for 5 times.
    for(int i=0;i<5;i++)
    {
        printf("Please enter username\n");
        scanf("%s",&username1);
        printf("Please enter password\n");
        scanf("%s",&password1);
        //Check if the user enterd a wrong username.
        if(strcmp(username,username1) != 0)
        {
            printf("Wrong Username\n");
            //Print the number of tries.
            printf("%d Tries left\n",4-i);
        }
        else 
        {
            //Check if the user entered a wrong password.
            if(strcmp(password,password1) != 0)
            {
                printf("Wrong Password\n");
                //Print the number of tries.
                printf("%d Tries left\n",4-i);
            }
            //If the the username and password are correct execute the code.
            else
            {
                while(cont=='1' && strlen(cont)==1)
        {
            //Ask for the operation.
            printf("Please enter A number for Operation\n1)Add Student\n2)Remove Student\n3)Retireve Student's Data\n4)Update Student's Data\n5)Return Students Data\n");
        scanf("%d",&oper);
        //Switch case on the entered value.
        switch(oper)
        {
            case 1:
            AddStudent();
            break;
            case 2:
            RemoveStudent();
            break;
            case 3:
            RetriveStudent();
            break;
            case 4:
            UpdateData();
            break;
            case 5:
            ReturnData();
            break;
            //If the user entered a different value.
            default:
            printf("Invalid Input\n");
            break;
        }
        //Ask the user to continue.
        printf("Please enter 1 to continue and any other key to exit\n");
    scanf(" %s",&cont);  
    }
    //Exit from the for loop.
    break;
            }
        }  
    }
    return 0;
}