#include "Headers.h"
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
extern patient *head;
int arr[5]={-1,-1,-1,-1,-1};
void displayAvailabeleSolts(void)
{
	printf ("Available Solts.\n");
	if(arr[0]==-1)
		printf("-2pm to 2:30pm...Press 1 to reserve.\n");
	if(arr[1]==-1)
		printf("-2:30pm to 3pm...Press 2 to reserve.\n");
	if(arr[2]==-1)
		printf("-3pm to 3:30pm...Press 3 to reserve.\n");
	if(arr[3]==-1)
		printf("-4pm to 4:30pm...Press 4 to reserve.\n");
	if(arr[4]==-1)
		printf("-4:30pm to 5pm...Press 5 to reserve.\n");
}
void Reserve(u32 ID)
{

	displayAvailabeleSolts();// Show Available Solts
	u32 input; // Choose The Solt To Reserve
	scanf("Enter Your Choice:");
	scanf("%d",&input);
	//input--; // To make input == the index of arr[]
	if (input>0&&input<6)// To make sure That The User Choosen right index in arr[]
	{
		if(arr[0]==-1&&input==1) // If The choosen Solt Was The First And it is empty.
		{
			arr[0]=ID;
		}
		else if (arr[1]==-1&&input==2)// If The choosen Solt Was The Secoend And it is empty.
		{
			arr[1]=ID;
		}
		else if(arr[2]==-1&&input==3)// If The choosen Solt Was The third And it is empty.
		{
			arr[2]=ID;
		}
		else if (arr[2]==-1&&input==4)// If The choosen Solt Was The 4th And it is empty.
		{
			arr[3]=ID;
		}
		else if (arr[4]==-1&&input==5)// If The choosen Solt Was The 5th And it is empty.
		{
			arr[4]=ID;
		}
		else 
			printf("Booked Solt !, Try Again."); // If He Choosen A Booked Solt.
			
	}
	else
	{
		printf("Wrong Choice !\n"); // IF He Choosen Valid Solt.
	}
}
void PrintReserved(void)
{
	printf("The Booked Solts.\n");
	if(arr[0]!=-1)
	{
		printf("1-From 2pm to 2:30pm Booked to ID :%d.\n",arr[0]);
	}
	if(arr[1]!=-1)
	{
		printf("2-From 2:30pm to 3pm Booked to ID :%d.\n",arr[1]);
	}
	if(arr[2]!=-1)
	{
		printf("3-From 3pm to 3:30pm Booked to ID :%d.\n",arr[2]);
	}
	if(arr[3]!=-1)
	{
		printf("4-From 4pm to 4:30pm Booked to ID :%d.\n",arr[3]);
	}
	if(arr[4]!=-1)
	{
		printf("5-From 4:30pm to 5pm Booked to ID :%d.\n",arr[4]);
	}
	if(arr[0]==-1&&arr[1]==-1&&arr[2]==-1&&arr[3]==-1&&arr[4]==-1)
	printf("No Solts Are Booked !\n");
}
void CancelResrve(void)
{
	PrintReserved();
	u32 input; // Choose The Solt To Cancel Reserve
	printf("Enter Your Choice:");
	scanf("%d",&input);
	//input--; // To make input == the index of arr[]
	if (input>0&&input<6)// To make sure That The User Choosen right index in arr[]
	{
		if(arr[0]!=-1&&input==1) // If The choosen Solt Was The First And it is empty.
		{
			arr[0]=-1;
		}
		else if (arr[1]!=-1&&input==2)// If The choosen Solt Was The Secoend And it is empty.
		{
			arr[1]=-1;
		}
		else if(arr[2]!=-1&&input==3)// If The choosen Solt Was The third And it is empty.
		{
			arr[2]=-1;
		}
		else if (arr[2]!=-1&&input==4)// If The choosen Solt Was The 4th And it is empty.
		{
			arr[3]=-1;
		}
		else if (arr[4]!=-1&&input==5)// If The choosen Solt Was The 5th And it is empty.
		{
			arr[4]=-1;
		}
		else 
			printf("The Choosen Solt is Already Empty !."); // If He Choosen A Booked Solt.
			
	}
}

void ChossenMode(u32 mode)
{
	if(mode==3) //Reserve solt Mode
	{
		u32 ID;
		printf("Enter The Patient ID:");
		scanf("%d",&ID); // Taking The ID To Reserve.
		if(check_ID(ID)!=NULL)//Check if the id is in the list.
		{
			Reserve(ID);
		}	
		else 
		{
		printf("ID Not Exist!\n");// if The ID Not Exist.
		}
	}
	else if (mode==4)//if He Choose to cancel reserve.
	{
		CancelResrve();
	}
	else
	{
		printf("Wrong mode !\n");//if He Choosen Wrong mode .
	}
}
void printList (void)
{
	printf("\n-Enter 1 to add new patient.");
	printf("\n-Enter 2 to Edit exist patient.");
	printf("\n-Enter 3 to reserve a solt with the doctor.");
	printf("\n-Enter 4 to cancel reservation.\n");
	printf("-Enter 5 to show all patients data.\n");
	printf("-Enter 6 to Exit Admin mode.\n");
	printf("-Enter 7 to Exit The Programe.\n");
}
void edit_Patient(patient *current)
{
	u32 choice;
	if (current==NULL)
	{
		printf("ID Not Found !\n");
		return;
	}
	printf("\nThe Current Data Of The Patient.\n");
	display(current);
	printf("-Enter 1 To Edit ID.\n");
	printf("-Enter 2 To Edit Name.\n");
	printf("-Enter 3 To Edit Age.\n");
	printf("-Enter 4 To Edit Gender.\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1: 
	printf("Enter The New ID:");
	scanf("%d",&current->ID);
	printf("Done !\n");
	break;
	case 2:
	printf("Enter The New Name:");
	scanf("%s",current->name);
	printf("Done !\n");
	break;
	case 3:
	printf("Enter The New Age:");
	scanf("%d",&current->age);
	printf("Done !\n");
	break;
	case 4: 
	printf("Enter The New Gender:");
	scanf("%s",current->gender);
	printf("Done !\n");
	break;
	default : printf("Wrong Choice !\n");		
	}		
}
void display_all(void)
{
	patient *current=head;
	if (current==NULL)
	{
		printf("Empty List !\n");
		return;
	}
	while(current!=NULL)
	{
		display(current);
		current=(current->next);
	}
}
patient* check_ID(u32 ID) //Check If The ID is Exist or not.
{
	patient *current = head;
		while(current!=NULL) // Loop On The List
		{
			if(current->ID==ID)
		{
				return current; //ID Exist
		}
			current=current->next;
		}
		return NULL; //ID Not Exist
}
patient* input_Data(patient *p)
{
	u32 ID;
	u32 check=0;
	while(check==0)
	{
		printf("Enter Patient ID:");
		scanf("%d",&ID);
		if(check_ID(ID)==NULL)
		{
			p->ID=ID;
			check=-1;
		}
		else 
		{
			printf("ID Already Taken !\n");
		}
	}

	printf("Enter Patient Name:");
	scanf("%s",p->name);
	printf("Enter Patient Age:");
	scanf("%d",&p->age);
	printf("Enter Patient Gender:");
	scanf("%s",p->gender);
	printf("\n======================================\n");

	return p;
}
void display(patient *pat)
{
	//Function To Print The Data of The patient that had been passed to the function.
	printf("\n======================================");
	printf("\nPatient ID :%d",pat->ID);
	printf("\nPatient Name :%s",pat->name);
	printf("\nPatient Age :%d",pat->age);
	printf("\nPatient Gender :%s",pat->gender);
	printf("\n======================================\n");
}
void add_patient(patient *pat)
{
	u32 size = sizeof(pat->name) / sizeof(pat->name[1]) ;
	// Function to add new record of a patient.
	patient *current = head; //pointer to loop on the list
	patient *temp = (patient*)malloc(sizeof(patient));	// create new node
	for(u16 i=0;i<=size;i++)
	{
		temp->name[i]=pat->name[i];
	}
	size = sizeof(pat->gender) / sizeof(pat->gender[1]) ;
	for(u16 i=0;i<=size;i++)
	{
		temp->gender[i]=pat->gender[i];
	}
	temp->ID=pat->ID;               //Put The Data Into Temp .
	temp->age=pat->age;
	temp->next=NULL;
	if(head==NULL) // If List is Empty
	{
		head=temp;
	}
	else 
	{
		while((current->next)!=NULL) // Move Until Founding the last record.
		{
			current=(current->next); // if not found move to next one.
		// This Loop "Must" exit with the last node in 'current'
		}
		(current->next)=temp; //but the new record at the end of the list.
	}
}