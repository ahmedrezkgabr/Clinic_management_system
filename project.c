/*
created by 		:Ahmed Rezk
e-mail 			:ahmedrezkofficial@gmail.com
mobile 			:+201001525033
githup 			:https://githup.com/ahmedrezkgabr
linked in		:https://www.linkedin.com/in/ahmed-rezk-926944199
date			:Sep, 2021
*/

/*
This is a C code for clinic management system. 
At the beginning of the system it asks the user to choose between admin mode and user mode.
 
In admin mode 
The system asks for password, the default password is 1234. 
The system allows 3 trails for the password entry, if the entered password was incorrect for 3 consecutive times, the system shall close. 
After login in the admin mode, the system shall provide the following features: 

1. Add new patient record: 
To add a new patient, 
the user shall admin shall enter these basic information: 
name, age, gender and ID. 
The ID shall be unique for the user, if the entered ID is already exists, the system shall reject the entry. 

2. Edit patient record 
By entering patient ID the system shall checks if the ID exists, the system shall allow the user to edit the patient information. 
If not, the system shall display incorrect ID message.
 
3. Reserve a slot with the doctor 
By default there are 5 available slots, 2pm to 2:30pm, 2:30pm to 3pm, 3pm to 3:30pm, 4pm to 4:30pm and 4:30pm to 5pm. 
Upon opening of this window, the system shall display the available slots. 
The admin shall enter the patient ID and the desired slot. The reserved slot shall not appear again in the next patient reservation.
 
4. Cancel reservation. 
The admin can cancel a reservation by entering the patient ID. 
This reservation shall be shown again in the available slots window.
 
In the user mode 
There is no password. 
The system allows the following features: 
1. View patient record. 
By entering the patient ID, the system shall show the basic information for the patient. 
2. View today’s reservations. 
In this view, the system shall print all reservations with the patient ID attached to each reservation slot. 
*/

#include<stdio.h>
#include"STD_Types.h"

/*struct that contain patient information*/
struct node
{
	u8 name[100];		/*patient name   */
	u8 age;				/*patient age    */
	u8 gender;			/*patient gender */
	u16 ID;				/*patient ID     */
};

/*global variables*/
u8 i = 0;			/*variable for index of the array of structs*/
u8 slots[5] = {0};	/*array of the slots						*/
u8 choice = 0;      /*variable for the choosing					*/

/*array of structs*/
struct node patients[20] = {0};

/*Admin mode functions*/
void add();
void edit();
void reserve();
void cancle();

/*User mode functions*/
void view();
void reservation();

/*entry point*/
int main(void)
{                                                                    
	u16 password;		/*Admin Password -> 1234                       */
	u8 counter = 0;		/*for 3 trails                                 */
	u8 flag;			/*indecation for is password enterd true or not*/
	while(1)
	{
		printf("\n");
		printf("----------------------------------------------\n");
		
		printf("WELLCOME\n");
		printf("1: for admin\n");
		printf("2: for user\n");
		
		printf("CHOOSE MODE\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:			/*Admin mode*/
				printf("\n");
				printf("WELCOME AT ADMIN MODE (:\n");
				
				/*log in process*/
				for(;;)
				{
					printf("\n");
					printf("Please enter the password\n");
					scanf("%d",&password);
					if(password == 1234)
					{
						printf("\n");
						printf("LOG IN (:\n");
						flag = 1;
						break;
					}
					if(counter == 2)
					{
						printf("\n");
						printf("YOU CAN NOT LOG IN ):\n");
						flag = 0;
						break;
					}
					printf("WRONG PASSWORD\n");
					counter++;
				}
				
				
				/*the actual actions of the admin*/
				if(flag == 1)
				{
					counter = 0;		/*making counter equal 0 for the next loop inside while(1)  */
					choice = 0;			/*making choice equal 0 to use it again in the next choosing*/
				
					printf("\n");
					printf("1: Add New Patient Record\n");
					printf("2: Edit Patient Record\n");
					printf("3: Reserve A Slot With The Doctor\n");
					printf("4: Cancle Reservation\n");
					
					printf("CHOOSE MODE\n");
					scanf("%d",&choice);
					
					switch(choice)
					{
						case 1:			/*Admin mode -> adding a new patient*/
							printf("\n");
							printf("1: Add New Patient Record\n");
							add();
							break;
							
						case 2:			/*Admin mode -> editng a patient information*/
							printf("\n");
							printf("2: Edit Patient Record\n");
							edit();
							break;
							
						case 3:			/*Admin mode -> reserving a slot for a patient*/
							printf("\n");
							printf("3: Reserve A Slot With The Doctor\n");
							reserve();
							break;
							
						case 4:			/*Admin mode -> cancling a slot of a patient*/
							printf("\n");
							printf("4: Cancle Reservation\n");
							cancle();
							break;
							
						default:
							printf("\n");
							printf("WRONG CHIOCE!!\n");
							break;
					}
				}
				break;
				
				
			case 2:			/*User mode*/
				choice = 0;			/*making choice equal 0 to use it again in the next choosing*/
				printf("\n");
				printf("WELCOME AT USER MODE (:\n");
				printf("1: View Patient Record\n");
				printf("2: View Today's Reservation\n");
				
				printf("CHOOSE MODE\n");
				scanf("%d",&choice);
				
				switch(choice)
				{
					case 1:			/*User mode -> viewing the information of a patient*/ 
						printf("\n");
						printf("1: View Patient Record\n");
						view();
						break;
						
					case 2:			/*User mode -> viewing the reservation of the slots*/
						printf("\n");
						printf("2: View Today's Reservation\n");
						reservation();
						break;
						
					default:
						printf("\n");
						printf("WRONG CHIOCE!!\n");
						break;
				}
				break;
				
				
			default:
				printf("\n");
				printf("WRONG CHIOCE!!\n");
				break;
		}
	}
}


void add()
{
/*
Function name			:add
Return					:void
Input					:void
Function description	:this function adds a patient in the array of struct by 
						1.finding the first empty place in the array 
						2.taking the information of the patient and assigne it in the strcut of the index which is result of finding
*/

	u16 cid;		/*the ID that will be serched for                    */
	i = 255;		/*index of the element that entered ID is belog to it*/ 
	
	/*finding the index of the first empty place in the array*/
	for(u8 j = 0; j < 20; ++j)
	{
		if(patients[j].age == 0)
		{
			i = j;
			break;
		}
	}
	
	/*taking the information of the patient*/
	printf("Enter Patient Name -->  	\n");
	scanf("\n");
	scanf("%[^\n]%*c",patients[i].name);
	printf("Enter Patient Age -->  		\n");
	scanf("%d",&patients[i].age);
	printf("Enter Patient Gender -->  	\n");
	scanf("%d",&patients[i].gender);
	printf("Enter Patient ID -->  		\n");
	scanf("%d",&patients[i].ID);
	/*checking if ID is here or not*/
	
}

void edit()
{	
/*
Function name			:edit
Return					:void
Input					:void
Function description	:this function edits a patient information in the array of struct by 
						1.taking the ID of desired patient
						2.finding the index of the patient in the array by the ID
						3.taking the new information of the patient and assigne it in the strcut of the index which is result of finding
*/
	u16 cid;		/*the ID that will be serched for                    */
	i = 255;		/*index of the element that entered ID is belog to it*/ 
	
	/*taking the ID*/
	printf("Enter Patient ID -->  \n");
	scanf("%d",&cid);
	
	/*is this ID is already here or not*/
	for(u8 j = 0; j < 20; ++j)
	{
		if(patients[j].ID == cid)
		{
			i = j;
			break;
		}
	}
	
	/*if it is not here*/
	if(i == 255)
	{
		printf("WRONG ID :( \n");
	}
	/*if this ID is here*/
	else
	{
		/*taking the new information of the patient*/
		printf("Enter Patient New Name -->  	\n");
		scanf("\n");
		scanf("%[^\n]%*c",patients[i].name);
		printf("Enter Patient New Age -->  		\n");
		scanf("%d",&patients[i].age);
		printf("Enter Patient New Gender -->  	\n");
		scanf("%d",&patients[i].gender);
		printf("Enter Patient New ID --> 		\n");
		scanf("%d",&patients[i].ID);
	}
}

void reserve()
{		
/*
Function name			:reserve
Return					:void
Input					:void
Function description	:this function reserves a slot in the array of slots by 
						1.taking the choice of the slot
						2.taking the the ID of the patient
						3.checking if this ID is here
						4.but the ID as an element of the index choosen
*/
	u16 cid;		/*the ID that will be serched for                           */
	choice = 0;		/*making choice equal 0 to use it again in the next choosing*/
	
	printf("1: from 14:00 to 14:30\n");
	printf("2: from 14:30 to 15:00\n");
	printf("3: from 15:00 to 15:30\n");
	printf("4: from 15:30 to 16:00\n");
	printf("5: from 16:00 to 16:30\n");
	
	/*printing the available slots*/
	printf("available :\n");
	for(int k = 0; k < 5; ++k)
	{
		if(slots[k] == 0)
		{
			printf("%d\t",k+1);
		}
	}
	printf("CHOOSE SLOT\n");
	scanf("%d",&choice);
	
	printf("Enter Patient ID -->  \n");
	scanf("%d",&cid);
	
	/*making sure that this ID is here*/
	for(u8 j = 0; j < 20; ++j)
	{
		if(patients[j].ID == cid)
		{
			i = j;
			break;
		}
	}
	
	/*if the ID is not here*/
	if(i == 255)
	{
		printf("WRONG ID :( \n");
	}
	/*if the ID is here*/ 
	else
	{
		/*but the ID as an element of the index choosen*/
		slots[choice-1] = cid;
	}
	
}


void cancle()
{
/*
Function name			:cancle
Return					:void
Input					:void
Function description	:this function cancles a slot in the array of slots by 
						1.taking the the ID of the patient
						2.checking if this ID is here
						3.replacing the ID with 0 in the array of slots
*/
	u16 cid;		/*the ID that will be serched for                    */
	i = 255;		/*index of the element that entered ID is belog to it*/ 
	
	printf("Enter Patient ID -->  \n");
	scanf("%d",&cid);
	
	/*checking if ID is here or not*/
	for(u8 k = 0; k < 5; ++k)
	{
		if(slots[k] == cid)
		{
			i = k;
			break;
		}
	}
	
	/*if ID is not here*/
	if(i == 255)
	{
		printf("\nWRONG ID :(\n");
	}
	/*if ID is here*/
	else
	{
		/*replacing the ID with 0*/
		slots[i] = 0;
	}
}

void view()
{
/*
Function name			:view
Return					:void
Input					:void
Function description	:this function views information of a patient
						1.taking the the ID of the patient
						2.checking if this ID is here
						3.printing the information of the patient
*/
	u16 cid;		/*the ID that will be serched for                    */
	i = 255;		/*index of the element that entered ID is belog to it*/ 
	
	printf("Enter Patient ID -->  \n");
	scanf("%d",&cid);
	
	/*checking if ID is here or not*/
	for(u8 j = 0; j < 20; ++j)
	{
		if(patients[j].ID == cid)
		{
			i = j;
			break;
		}
	}
	
	/*if ID is not here*/
	if(i == 255)
	{
		printf("WRONG ID :( \n");
	}
	/*if ID is here*/
	else
	{
		/*printing the information of the patient*/
		printf("THE Patient Name --> 	");
		printf("%s\n",patients[i].name);
		printf("THE Patient Age --> 	");
		printf("%d\n",patients[i].age);
		printf("THE Patient Gender --> 	");
		printf("%d\n",patients[i].gender);
		printf("THE Patient ID --> 		");
		printf("%d\n",patients[i].ID);
	}
}

void reservation()
{
/*
Function name			:reservation
Return					:void
Input					:void
Function description	:this function views the reservation of the slots
*/
	/*printing the slots with its IDs*/
	printf("1: from 14:00 to 14:30 -> %d\n",slots[0]);		/*1: from 14:00 to 14:30*/ 
	printf("2: from 14:30 to 15:00 -> %d\n",slots[1]);		/*2: from 14:30 to 15:00*/
	printf("3: from 15:00 to 15:30 -> %d\n",slots[2]);		/*3: from 15:00 to 15:30*/
	printf("4: from 15:30 to 16:00 -> %d\n",slots[3]);		/*4: from 15:30 to 16:00*/
	printf("5: from 16:00 to 16:30 -> %d\n",slots[4]);		/*5: from 16:00 to 16:30*/
}


