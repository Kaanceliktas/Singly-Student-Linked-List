// KAAN ÇELÝKTAÞ
// DATA STRUCTURES AND ALGORITHMS PROJECT 1

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<string.h>
#include <stdbool.h>

struct Student // head struct with Student name
{
    int numberofstudents;
    float mid,prj,final,hmw;
    int lettergrade;
	int studentnumber;
    char name[40];
    char lastname[40];
    int birthyear;
    float totalgrade;
    struct Student *next;
    
}* head;



void insert(int studentnumber, char* name,char* lastname, int birthyear, float totalgrade, float hmw, float prj, float final, float mid) // insert function to save the students
{
    
    struct Student * student = (struct Student *) malloc(sizeof(struct Student)); // reserve a place in student for inserted students
    
    student->studentnumber = studentnumber;
    strcpy(student->name, name);
    strcpy(student->lastname, lastname);
    student->birthyear = birthyear;
    student->totalgrade = totalgrade;
   
    student->next = NULL;
    
    
    if(head==NULL)
	{
       
        head = student;
    }
    else
	{
        
        student->next = head; // to add next node in list
        head = student;
    }
    
}

void search(int studentnumber) // search function to find students by their studend id
{
    struct Student * temp = head;
    while(temp!=NULL){
        if(temp->studentnumber==studentnumber)
		{
            printf("Student Number: %d\n", temp->studentnumber);
            printf("Name: %s\n", temp->name);
            printf("Surname: %s\n", temp->lastname);
            printf("Birth Year: %s\n", temp->birthyear);
            printf("Total Grade: %0.2f\n", temp->totalgrade);
            return;
        }
        temp = temp->next;
    }
    printf("Student with student number %d is not found !!!\n", studentnumber);
}



void update(int studentnumber) // update function to fiz the wrong entries
{
    
    struct Student * temp = head;
    while(temp!=NULL)
	{
        
        if(temp->studentnumber==studentnumber)
		{	
			printf("Record with student number %d found and prepared for changing !\n", studentnumber);
        	printf("Enter new name: ");
            scanf("%s", &temp->name);
            printf("Enter new surname: ");
            scanf("%s", &temp->lastname);
            printf("Enter new birthyear number: ");
            scanf("%d", &temp->birthyear);
            printf("Enter project,homework,midterm and final grades: \n");
            scanf("%f %f %f %f",&temp->prj,&temp->hmw,&temp->mid,&temp->final);
                       
            temp->totalgrade=(float)((temp->mid*20)/100)+((temp->hmw*20)/100)+((temp->prj*30)/100)+((temp->final*30)/100);
            
            printf("Updation Successful !\n");
            
            return;
        }
        temp = temp->next;
        
    }
    printf("Student with student number %d is not found !\n", studentnumber);
    
}

void Delete(int studentnumber) // delete function when we wanted to delete the saved student
{
    struct Student * temp1 = head;  // deleting operations
    struct Student * temp2 = head;  // deleting operations
    while(temp1!=NULL){
        
        if(temp1->studentnumber==studentnumber){
            
            printf("Record with student number %d Found !!!\n", studentnumber);
            
            if(temp1==temp2){
                // this condition will run if
                // the record that we need to delete is the first node
                // of the linked list
                head = head->next;
                free(temp1);
            }
            else{
                // temp1 is the node we need to delete
                // temp2 is the node previous to temp1
                temp2->next = temp1->next;
                free(temp1); 
            }
            
            printf("Record Successfully Deleted !!!\n");
            return;
            
        }
        temp2 = temp1;
        temp1 = temp1->next;
        
    }
    printf("Student with student number %d is not found !!!\n", studentnumber);
    
}

void reverselist() // reverse the list by entry times
{
    struct Student * temp = head; // start from beginning of the list
    while(temp!=NULL)
	{
        
        printf("Student Number: %d\n", temp->studentnumber);
        printf("Name: %s\n", temp->name);
        printf("Surname: %s\n", temp->lastname);
        printf("Birth Year: %d\n", temp->birthyear);
        printf("Total Grade: %lf\n", temp->totalgrade);
        
        if(temp->totalgrade>95&&temp->totalgrade<=100)
		{
			printf("Letter Grade is Honored\n\n");
		}
		else if(temp->totalgrade>90&&temp->totalgrade<=95)
		{
		printf("Letter Grade is A\n\n");
		}
		else if(temp->totalgrade>80&&temp->totalgrade<91)
		{
			printf("Letter Grade is B\n\n");
		}
		else if(temp->totalgrade>70&&temp->totalgrade<81)
		{
			printf("Letter Grade is C\n\n");
		}
		else if(temp->totalgrade>60&&temp->totalgrade<71)
		{
			printf("Letter Grade is D\n\n");
		}
		else if(temp->totalgrade>49&&temp->totalgrade<61)
		{
			printf("Letter Grade is E\n\n");
		}
		else if(temp->totalgrade>=0&&temp->totalgrade<50)
		{
			printf("Letter Grade is F\n\n");
		}
		else
		{
			printf("Invalid total\n\n");
		}
     	   temp = temp->next; // to print all things
        
   	    }
}

void searchbylastname(char *lastname) // search function to find students by their lastname
{
    struct Student * temp = head;
    while(temp!=NULL)
	{	
		if(strcmp(temp->lastname, lastname) == 0){
		
            printf("Student Number: %d\n", temp->studentnumber);
            printf("Name: %s\n", temp->name);
            printf("Surname: %s\n", temp->lastname);
            printf("Birth Year: %d\n", temp->birthyear);
            printf("Total Grade: %0.2f\n", temp->totalgrade); 
			return;     
        }
        temp = temp->next;
    }
    printf("Student with student number %s is not found !!!\n", lastname);
}




typedef struct node2 //	defining the structs and nodes to use in pop adn push 
	   {
	    void* dataPtr;
	    struct node2* link;
	   } STACK_NODE;

typedef struct STACK //	defining the structs and nodes to use in pop adn push 
	   {
	    int count; 
	    STACK_NODE* top; 
	   } STACK;


bool pushStack (struct STACK* stack, int* dataInPtr)
{
//	Local Definitions 
	STACK_NODE* newPtr;

//	Statements 
	newPtr = (STACK_NODE* ) malloc(sizeof(STACK_NODE));
	if (!newPtr)
	    return false;

	newPtr->dataPtr = dataInPtr; 

	newPtr->link    = stack->top; 
	stack->top      = newPtr; 

	(stack->count)++; 
	return true;
}	// pushStack 

void* popStack (STACK* stack) 
{
//	Local Definitions 
	void*       dataOutPtr; 
	STACK_NODE* temp;

//	Statements 
	if (stack->count == 0){
	
	    dataOutPtr = NULL;
	}
	else
	   {
	    temp       = stack->top;
	    dataOutPtr = stack->top->dataPtr;
	    stack->top = stack->top->link;
	    free (temp);
	    (stack->count)--;
	   } // else 
	return dataOutPtr;
}	// popStack 

void* stackTop (STACK* stack)
{
//	Statements 
	if (stack->count == 0){
	
	
	    return NULL;
	}    
	else
	    return stack->top->dataPtr;
}	// stackTop 

bool emptyStack (STACK* stack) 
{
//	Statements 
	return (stack->count == 0);
}	


/* LETTER GRADE TRYING
float calculateAverageFinalGrade() {
	
	struct Student * temp = head;
	
	int count = 0;
	float avg,total = 0;	
	
    while(temp!=NULL){
        
        total += temp->totalgrade;
        temp = temp->next;
        count++;
    }
    avg = total / count;
    return avg;	
}
*/



void printdisplay() // displaying the list by their entries normally 
{
	struct Student *head;
	int* dataPtr;
	dataPtr = (int*) malloc (sizeof(int));
    // store Node addresses in stack
    struct STACK *stk;
    struct Student* ptr = head;
    while (ptr != NULL) { 
        pushStack(stk, &ptr->studentnumber);
        ptr = ptr->next;
    }
 	
    // print data from stack
    while (!emptyStack(stk)) {
        dataPtr = (int*)popStack(stk);
	    printf ("%3d\n", *dataPtr);
    } 
    
    
} 



int main() //	main part that we called the functions in cases
{
    head = NULL;
    int choice;
    char name[50];
    char lastname[50];
    int birthyear;
    int studentnumber;
    float totalgrade;
    float prj,hmw,mid,final;
    struct Student * temp = head;
    label:
    	
    printf("1 for new entry student \n2 to update for student \n3 to display reverselist by entering the records\n4 to search for student \n5 to delete students\n6 to search by last name\n7-To reverselist the list");
    
    	
    		
        printf("\nEnter Choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter student number: ");
                scanf("%d", &studentnumber);
                printf("Enter name: ");
                scanf("%s", &name);
                printf("Enter surname: ");
                scanf("%s", &lastname);
                printf("Please enter 4 digit birthyear number: ");
                scanf("%d", &birthyear);
                printf("Enter project,homework,midterm and final grades: \n");
                scanf("%f %f %f %f",&prj,&hmw,&mid,&final);
                totalgrade=((mid*20)/100)+((hmw*20)/100)+((prj*30)/100)+((final*30)/100);
                insert(studentnumber, name, lastname, birthyear, totalgrade, hmw, prj, final, mid);
                break;
                
            case 2:
            	printf("Enter student number to update: ");
                scanf("%d", &studentnumber);
                update(studentnumber);
                break;            
                           
            case 3:
                reverselist();
            	break;
            
            case 4:
            	printf("Enter student number to search: ");
                scanf("%d", &studentnumber);
                search(studentnumber);
                break;
			
			case 5:
            	printf("Enter student number to delete: ");
                scanf("%d", &studentnumber);
                Delete(studentnumber);
                break;
			case 6:
				printf("Enter student lastname to search: "); 
				scanf("%s", &lastname);
				searchbylastname(lastname);
				break;
			case 7:
				printdisplay();
				break;	              
        }
        
        goto label;
        
    return 0;
        
     
}
