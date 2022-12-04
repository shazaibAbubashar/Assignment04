#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct Patient
{
    char id[20];
    char Name[30];
    char CNIC[30];
    char  phonenumber[30];
    char disease[30];
    char isAdmitted[20];
}info;
int flag=0;
//struct Patient info;
 FILE *ptr;
 FILE *ptr2;
void addPatient();
void DeleteRecord();
void passing_id();
void search_patient();
void PatientRecord();
int main(void){
	fread(&info,sizeof(struct Patient),1,ptr);
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
        case 1:{
        	system("cls");
            addPatient();
            system("cls");
        
			break;
		}
            
        case 2:{
        
        
            //system("cls");
           DeleteRecord();
           
           //FILE *ptr2;
          // ptr2=fopen("PatientRecord.txt", "a");
          // fclose(ptr2);
         //  printf("Press any key to exit\n");
          // system("cls");
        
			break;
		}
		case 3:{
			//printf("\n Enter the id you want to delete :: ");
		//	scanf("%s",info.id);
			passing_id();
			break;
		}
		case 4:{
			search_patient();
			break;
		}
		
		case 5:
			system("cls");
			
			PatientRecord();
//			system("cls");
           break;
        default:{
        	printf("You ENTER INAVALID INPUT::");
			break;
		}
        
        }
    }

    return 0;
}
void addPatient()
{
    
   
    char another;
    

    do
    {
        system("cls");
        printf("\n\n\t\t================Add Patient Info================\n\n");
        ptr = fopen("PatientRecord.txt", "a");
        printf("\t\tEnter Id of a Patient: ");
        scanf("%s", &info.id);
        fprintf(ptr,"\n%s\n",info.id);
        printf("\t\tEnter Name of a person: ");
        getchar();
        gets(info.Name);
        fprintf(ptr,"%s\n",info.Name);
        printf("\t\tEnter CNIC of a Person: ");
        scanf("%s", &info.CNIC);
        fprintf(ptr,"%s\n",info.CNIC);
        printf("\t\tEnter the phone number of a Patient: ");
        scanf("%s",&info.phonenumber);
        fprintf(ptr,"%d\n",info.phonenumber);
        printf("\t\tEnter disease of a Person: ");
        getchar();
        gets(info.disease);
        fprintf(ptr,"%s\n",info.disease);
        printf("\t\tEnter the status if the person isAdmitted in Yes or No form: ");
        gets(info.isAdmitted);
        fprintf(ptr,"%s\n",info.isAdmitted);
        if (ptr == NULL)
        {
            printf("Error!File could not be opened");
        }
        else
        {
            printf("\t\tRecord Successfully Updated");
        }
        // fwrite(&info, sizeof(struct Patient), 1, ptr);
        fclose(ptr);
        printf("\n\t\tDo you want another record(y/n): ");
        scanf("%s", &another);
        
    } while (another == 'y' || another == 'Y');
}
void DeleteRecord(){
	char id[20];
	//ptr=fopen("PatientRecord.txt","r");
	//	struct Patient stu;
	ptr=fopen("PatientRecord.txt","r");
        //	fread(&info,sizeof(struct Patient),1,ptr);
        	ptr2=fopen("copy.txt","a");
        	int flag=0;
	if(ptr==NULL || ptr2==NULL){
		fprintf(stderr,"\nError opening the file :\n");
	}
		//fread(&info,sizeof(struct Patient),1,ptr);
		printf("\nEnter the record you want to delete :: ");
	scanf("%s",id);
	fscanf(ptr,"%s",info.id);
	printf("\n%s",info.id);
	
//	while(fread(&info,sizeof(struct Patient),1,ptr)>0){
		//	printf("\n%s and %d",info.id,sizeof(info.id));
	//printf("\n%s and %d",id,sizeof(id));
	//	printf("ppp");

		if((strcmp(id,info.id))!=0){
		
	//if(s1.id == id){
	
			
			flag++;
			fwrite(&info,sizeof(struct Patient),1,ptr2);
			//fprintf(ptr2,"%d\n %s \n%d\n %d \n%s \n %s",s1.id,s1.Name,s1.CNIC,s1.phonenumber,s1.disease,s1.isAdmitted);
		}
		else{
			flag++;
		}
//	}
	if(flag==0){
		fprintf(stdout,"\nRecord doest not find\n");
	}
        	fclose(ptr2);
	fclose(ptr);
	if(flag>=1){
		remove("PatientRecord.txt");
		rename("copy.txt","PatientRecord.txt");
		printf("Succedfully deleted the record:: ");
		
	}
	
}
void passing_id(){
	char id[20];
	printf("Enter the id you want to Update :: ");
	scanf("%s",&id);
	ptr=fopen("PatientRecord.txt","w+");
	ptr2=fopen("copy1.dat","a+");
	if(ptr==NULL || ptr2==NULL){
	fprintf(stdin,"Print Error message ");
	exit(1);
	
	}
	//struct Patient_record s1;
	while(fread(&info,sizeof(struct Patient),1,ptr)){
		if((info.id != id)){
			fwrite(&info,sizeof(struct Patient),1,ptr2); 
} 
}
struct Patient info={
		"12","Hasnain","3820261","0304","DNGUE","25 dATE"
	};
	fwrite(&info,sizeof(struct Patient),1,ptr2);
	fclose(ptr);
	fclose(ptr2);
	remove("copy1.dat");
	rename("copy1.dat","PatientRecord.txt");
}
void search_patient(){
	char id[20];
	//FILE *ptr1;
	ptr=fopen("PatientRecord.txt","r+");
	if(ptr==NULL){
		printf("The file does not open yet :: ");
		
	}
	printf("Enter the id you want to searh :: ");
	scanf("%s",id);
	//struct Patient_record s1;
	int flag=0;
	
	while(fread(&info,sizeof(struct Patient),1,ptr)>0 && flag==0){
		if(info.id==id){
			flag=1;
			printf("ID : %d \nName: %s \nCinic: %d \nPnbr: %d \nDisease: %s ISAdmitted:: %s",info.id,info.Name,info.CNIC,info.phonenumber,info.disease,info.isAdmitted);
			
		}
	}
	if(flag==0){
		printf("\nThe required searching is'nt found:: ");
	}
	fclose(ptr);
	
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
        printf("\n\t\tPatient Id : %s",info.id);
        printf("\n\t\tPatient name : %s",info.Name);
        printf("\n\t\tPatient CNIC: %s",info.CNIC);
        printf("\n\t\tPatient PhoneNumber: %s",info.phonenumber);
        printf("\n\t\tPatient Disease: %s",info.disease);
        printf("\n\t\tPatient isAdmitted: %s",info.isAdmitted);
    }
    fclose(ptr);
    
}
