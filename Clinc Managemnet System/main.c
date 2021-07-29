#include <stdio.h>
#include <stdlib.h>
#include "Headers.h"
#include "LinkedList.h"
patient *head;
void main(void)
{
	u32 input;
	patient p;
	u8 i;
	u32 ExitFlag2=0;
	while(ExitFlag2==0)
	{
		printf("-Enter 1 to enter admin mode. \n-Enter 2 to enter user mode.\n");
		scanf("%d",&input);
		if(input==1)//admin mode.
		{
			for(i=0;i<3;i++)//loop Three times (Password).
			{
				printf("Please enter the password :");
				scanf("%d",&input);
				if(input==1234)//if the password is true get out,
				{
					break;
				}
			}
			if(i!=3)//if the password entered correctly.
			{
				u32 ExitFlag=0;
				while(ExitFlag==0)
				{
					u32 ID;
					printList();
					scanf("%d",&input);
					switch(input)
					{
						case 1: add_patient(input_Data(&p));
						break;
						case 2:
						printf("Enter The ID.");
						scanf("%d",&ID);
						edit_Patient(check_ID(ID));
						break;
						case 3: ChossenMode(3);
						break;
						case 4: ChossenMode(4);
						break;
						case 5:display_all();
						break;
						case 6:ExitFlag=-1;
						break;
						case 7:
						ExitFlag2=-1;
						ExitFlag=-1;
						break;
						default:printf("Wrong Choice !.\n");
					}
				}	
			}
				else 
				{
					printf("-The entered password was incorrect for 3 consecutive times.\n");
					return;
				}
		}
		else if (input==2)
		{
			u32 ExitFlag=0;
			while(ExitFlag==0)
			{
				printf("-Enter 1 To view patient Record By ID.\n");
				printf("-Enter 2 To View todays reservations.\n");
				printf("-Enter 3 To Exit User Mode.\n");
				printf("-Enter 4 To Exit The Programe.\n");
				scanf("%d",&input);
				switch(input)
				{
					u32 ID;
					case 1: display(check_ID(ID));
					break;
					case 2: PrintReserved();
					break;
					case 3:ExitFlag=-1;
					break;
					case 4:
					ExitFlag2=-1;
					ExitFlag=-1;
					break;
					default:printf("Wrong Chioce !.\n");
				}
			}
		}
		else
		{
			printf("Wrong Choice Try Again !.");
		}	
	}
}