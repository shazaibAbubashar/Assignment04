#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct Patient_record{
	int id;
	char name[100];
	int Cnic;
	int Pnbr;
	char disease[20];
	char IsAdmitted[20];
};
int P_id;
void passing_id(int);
void search_patient();
int main(void){
	printf("Enter your Choice:: ");
	printf("\n\t***********");
	printf("\n3-->> Update the Patient  ");
	printf("\n4-->> Searching the Patient  ");
	printf("\n5-->> Display All the Patient  ");
	printf("\n\t***********");
	int choice;
	printf("\nEnter the choice of work you wanaa perform:: ");
	scanf("%d",&choice);
	switch(choice){
		case 3:{
			printf("\nYOU HAVE ELECTED UPDATE THE PATIENT OPTION :: \n");
			printf("\nEnter the id of the Patient :: \n");
			scanf("%d",& P_id);
			passing_id(P_id);
			
			break;
		}
		case 4:{
			printf("\nYOU HAVE SELECTED THE SEARCHING OPTION TO SEARCH THE PARTICULAR RECOR OF PATIENT :: ");
			search_patient();
			break;
		}
			
	}
	
	
}
void passing_id(int P_id){
	FILE *ptr1,*ptr2;
	ptr1=fopen("had","w+");
	ptr2=fopen("copy.dat","a+");
	if(ptr1==NULL || ptr2==NULL){
	fprintf(stdin,"Print Error message ");
	exit(1);
	
	} 
	
	struct Patient_record s1;
	while(fread(&s1,sizeof(struct Patient_record),1,ptr1)){
		if((s1.id != P_id)){
			fwrite(&s1,sizeof(struct Patient_record),1,ptr2);
		}	
	}
	struct Patient_record s2={
		12,"Hasnain",3820261,0304,"DNGUE","25 dATE"
	};
	fwrite(&s2,sizeof(struct Patient_record),1,ptr2);
	
	
	
	
	
	
	
	
	fclose(ptr2);
	fclose(ptr1);
}
void search_patient(){
	FILE *ptr1;
	ptr1=fopen("had","r+");
	if(ptr1==NULL){
		printf("The file does not open yet :: ");
		
	}
	printf("Enter the id you want to searh :: ");
	scanf("%d",&P_id);
	struct Patient_record s1;
	int flag=0;
	
	while(fread(&s1,sizeof(	struct Patient_record),1,ptr1)>0 && flag==0){
		if(s1.id==P_id){
			flag=1;
			printf("ID : %d \nName: %s \nCinic: %d \nPnbr: %d \nDisease: %s ISAdmitted:: %s",s1.id,s1.name,s1.Cnic,s1.Pnbr,s1.disease,s1.IsAdmitted);
			
		}
	}
	if(flag==0){
		printf("\nThe required searching is'nt found:: ");
	}
	fclose(ptr1);
	
}