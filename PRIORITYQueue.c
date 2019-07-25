#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

//Data Structure Declaration
struct Element
{
 int value;
 int priority;
 struct Element *next;
};

struct Element *FRONT=NULL,*REAR=NULL,*temp=NULL,*head=NULL;


int SIZE=5,COUNT=0;

//Function Declaration
void enqueue(int,int);
void dequeue();
void displayQueue();
int countElement();
void sort();

//Main Function
int main()
{
 int choice,priority,value;
 //You are free to create more variable, if needed
 do
 {
  system("cls"); // To clear the screen
  printMenu();
  printf("\nEnter Your Choice : ");
  scanf("%d",&choice);

  switch(choice)
  {
   case 1:
      if(COUNT<SIZE)
      {
       printf("\n Enter Value for Element : ");
       scanf("%d",&value);
       printf("\n Enter Priority for Element : ");
       scanf("%d",&priority);
       enqueue(value,priority);
    COUNT++;
   }
   else
   {
    printf("\n Queue is Overflow");
   }

    break;

   case 2:
      if(COUNT>0)
      {
       dequeue();
    COUNT--;
   }
   else
   {
    printf("\n Queue is Underflow");
   }
    break;

   case 3:
      if(COUNT>0)
      {
       displayQueue();
   }
   else
   {
    printf("\n Queue is Empty");
   }

    break;

   case 4:
     printf("\n No of Element in Queue : %d",countElement());
    break;


   default:
    printf("Thanks for Using Queue Program");
  }

  getch(); //To stop output on Screen

 }while(choice>0 && choice<5);
 return 0;
}


//Function Implementation
void printMenu()
{
 printf("\n==============================");
 printf("\nPRIORITY QUEUE OPERATION MENU");
 printf("\n==============================");
 printf("\n     1 - ENQUEUE");
 printf("\n     2 - DEQUEUE");
 printf("\n     3 - DISPLAY");
 printf("\n     4 - SIZE");
 printf("\n     5 - EXIT");
 printf("\n==============================");
}

void enqueue(int value,int priority)
{
 temp=(struct Element *)malloc(sizeof(struct Element)*1);
 temp->value=value;
 temp->priority=priority;
 temp->next=NULL;
 printf("\n IN Function");

 if(FRONT==NULL) //executed when null
 {
  FRONT=temp;
  REAR =temp;
  printf("\n IN NULL");
 }
 else if(FRONT->next==NULL)
 {
  if(temp->priority > FRONT->priority)
  {
   temp->next=FRONT;
   FRONT=temp;
  }
  else
  {
   REAR->next=temp;
   REAR=temp;
  }
 }
 else
 {
  head=FRONT;
  if(temp->priority > head->priority)
  {
   temp->next=FRONT;
   FRONT=temp;
  }
  else
  {
  while(temp->priority <= (head->next)->priority)
  {
   head=head->next;
   if(head->next==NULL)
   {
    break;
   }
  }

  if(head->next==NULL)
  {
   REAR->next=temp;
   REAR=temp;
  }
  else if(temp->priority > (head->next)->priority)
  {
   temp->next=head->next;
   head->next=temp;
  }
 }
 }
}

void dequeue()
{
 temp=FRONT;
 FRONT=FRONT->next;
 free(temp);
}


void displayQueue()
{
 head=FRONT;
 while(head!=NULL)
 {
  printf(" |%d|%d| -> ",head->value,head->priority);
  head=head->next;
 }
}

int countElement()
{
 return COUNT;
}
