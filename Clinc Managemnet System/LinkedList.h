#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
typedef struct patient_Node patient;
void displayAvailabeleSolts(void);
void Reserve(u32 ID);
void PrintReserved(void);
void CancelResrve(void);
void ChossenMode(u32 mode);
void printList (void);
void edit_Patient(patient *current);
void display_all(void);
patient* check_ID(u32 ID);
patient* input_Data(patient *p);
void add_patient(patient *pat);
void display(patient *pat);
struct patient_Node
{
    u8 name[60];
	u8 gender[5];
	u32 ID;
	u32 age;
	patient *next;
};
#endif