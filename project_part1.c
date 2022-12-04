#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void PatientRecord();
void addPatient();
void DeleteRecord();
struct Patient
{
    char Id[100];
    char Name[300];
    char CNIC[500];
    char phonenumber[300];
    char disease[30];
    char isAdmitted[20];
};

int main()
{

    int choice;
    while (choice != 6)
    {
        printf("\nEnter 1 for Add Patient\n");
        printf("Enter 2 for Delete Patient\n");
        printf("Enter 3 for Update Record\n");
        printf("Enter 4 for search Patient Records\n");
        printf("Enter 5 for Display All Patient\n");
        printf("Enter 6 for exit\n");
        printf("Enter Your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            addPatient();
            system("cls");
            break;
        case 2:
            system("cls");
            DeleteRecord();
            break;
            case 5:
            system("cls");
            PatientRecord();
            printf("Press any key to exit\n");
            break;
        default:
            break;
        }
    }

    return 0;
}
void addPatient()
{
    struct Patient info;
    FILE *ptr;
    char another;

    do
    {
        system("cls");
        printf("\n\n\t\t================Add Patient Info================\n\n");
        ptr = fopen("PatientRecord.txt", "a");
        printf("\t\tEnter Id of a Patient: ");
        scanf("%s", &info.Id);
        // fprintf(ptr, "\n%s\n", info.Id);
        printf("\t\tEnter Name of a person: ");
        getchar();
        gets(info.Name);
        // fprintf(ptr, "%s\n", info.Name);
        printf("\t\tEnter CNIC of a Person: ");
        scanf("%s", &info.CNIC);
        // fprintf(ptr, "%s\n", info.CNIC);
        printf("\t\tEnter the phone number of a Patient: ");
        scanf("%s", &info.phonenumber);
        // fprintf(ptr, "%s\n", info.phonenumber);
        printf("\t\tEnter disease of a Person: ");
        getchar();
        gets(info.disease);
        // fprintf(ptr, "%s\n", info.disease);
        printf("\t\tEnter the status if the person isAdmitted in Yes or No form: ");
        gets(info.isAdmitted);
        // fprintf(ptr, "%s\n", info.isAdmitted);
        if (ptr == NULL)
        {
            printf("Error!File could not be opened");
        }
        else
        {
            printf("\t\tRecord Successfully Updated");
        }
        // fwrite(&info, sizeof(struct Patient), 1, ptr);
        fwrite(&info,sizeof(struct Patient),1,ptr);
        fclose(ptr);
        printf("\n\t\tDo you want another record(y/n): ");
        scanf("%s", &another);

    } while (another == 'y' || another == 'Y');
}
void DeleteRecord()
{
    FILE *ptr1,*ptr2;
    struct Patient info;
    char id[20];
    printf("Enter the id where you want to delete a record: ");
    scanf("%s",id);
    ptr1=fopen("PatientRecord.txt","r+");
    ptr2=fopen("temp.txt","a+");
    if (ptr1==NULL||ptr2==NULL)
    {
       fprintf(stderr,"Error!File could not be opened\n");
    }
   while (fread(&info,sizeof(struct Patient),1,ptr1))
   {
        if (info.Id!=id)
        {
            fwrite(&info,sizeof(struct Patient),1,ptr2);
        }
        else{
        	printf("Record not found\n");
		}
   }
   
    fclose(ptr1);
    fclose(ptr2);
    remove("PatientRecord.txt");
    rename("temp.txt","PatientRecord.txt");
    printf("Record deleted successfully!!!");
    
}

void PatientRecord()
{
    FILE *ptr;
    struct Patient info;
    
    ptr=fopen("PatientRecord.txt","r");
    if (ptr==NULL)
    {
       fprintf(stderr,"Error!File could not be opened");
    }
     else
     {
         printf("\t\t===============Records=================\n\n");
     }
   
    
    while(fread(&info,sizeof(struct Patient),1,ptr));
    {
        fseek(ptr,0,SEEK_SET);
        printf("\n\t\tPatient Id : %s\n",info.Id);
        printf("\n\t\tPatient name : %s\n",info.Name);
        printf("\n\t\tPatient CNIC: %s\n",info.CNIC);
        printf("\n\t\tPatient PhoneNumber: %s\n",info.phonenumber);
        printf("\n\t\tPatient Disease: %s\n",info.disease);
        printf("\n\t\tPatient isAdmitted: %s\n",info.isAdmitted);
    }
    fclose(ptr);
    
}