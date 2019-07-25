#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

//Data Structure Declaration
struct Element
{
 int value;
 struct Element *next;
};

struct Element *TOS=NULL,*temp=NULL,*first=NULL,*head=NULL;
//You are free to create more pointers, if needed

//Stack Size, Show Overflow for > 5
int SIZE=0,count=0,position;

//Function Declaration
void push(int);
void pop();
void peek();
void peep(int );
void displayStack();
int countElement();

//Main Function
int main(int argc,char*argv[])
{
 int choice,postion,value;
 //You are free to create more variable, if needed
 SIZE=atoi(argv[1]);
 do
 {
  system("cls"); // To clear the screen
  printMenu();
  printf("\nEnter Your Choice : ");
  scanf("%d",&choice);

  switch(choice)
  {
   case 1:
       if(countElement()<5){
        push(value);
       }
       else{
        printf("\nThe Stack is Overflowed!");
       }
    break;

   case 2:
       pop();
    break;

   case 3:
       peek();
    break;

   case 4:

            if(first == NULL)
            {
                printf("\n\n\tThe STACK is empty.");
            }
            else
            {
                printf("\n\n\tEnter the position. ");
                scanf("%d",&position);
                if(position<=countElement() && position>0)
                {
                    peep(position);
                }
                else
                {
                    printf("\n\n\tThe position is not available.");
                }
            }
    break;

   case 5:
        displayStack();
    break;

   case 6:
       countElement();
    break;
   default:
    printf("Thanks for Using Stack Program");
  }

  getch(); //To stop output on Screen

 }while(choice>0 && choice<6);
 return 0;
}


//Function Implementation
void printMenu()
{
 printf("\n==============================");
 printf("\n    STACK OPERATION MENU");
 printf("\n==============================");
 printf("\n     1 - PUSH");
 printf("\n     2 - POP");
 printf("\n     3 - PEEK");
 printf("\n     4 - PEEP");
 printf("\n     5 - DISPLAY");
 printf("\n     6 - COUNT NO OF ELEMENT");
 printf("\n     7 - EXIT");
 printf("\n==============================");
}

void push(int value)
{
        temp=(struct Element *)malloc(sizeof(struct Element)*1);
        head=(struct Element *)malloc(sizeof(struct Element)*1);

        printf("\nEnter Value For New Node:");
        scanf("%d",&temp->value);
        TOS=temp;
        temp->next=NULL;

        //To attach Node in LL
        if(first==NULL){
            first=temp;
        }
        else{
            head=first;
            while(head->next!=NULL){
                head=head->next;
            }
                head->next=temp;
}//Check Overflow condition Max Size = 5
}

void pop()
{
 head=first;
 if(head==TOS){

    first=NULL;
    TOS=NULL;
    printf("THE STACK IS EMPTY!");
 }else{
 while(head->next!=TOS){
    head=head->next;
 }
 head->next=NULL;
 TOS=head;
 printf("\nThe Operation has been successfully done");
 printf("\nThe Stack is:");
 displayStack();
 countElement();
 //Check underflow condition as POP not possible with Empty Stack
}
}
void peek()
{
 //Display Value of TOS
if(countElement()==0){
    printf("\nThe Stack is:NULL");
}
 printf("\nThe Value at TOS is:%d",TOS->value);
}

void peep(int pos)
{
//Display Value of element at given pos
    head = first;
    while(pos>1)
    {
        head = head->next;
        pos--;
    }
    printf("\n\n\tThe node is %d",head->value);
}

void displayStack()
{

    head=first;
  if(head==NULL){
                printf("THE STACK IS EMPTY");
            }
            else{            while(head!=NULL){
                    printf("%d ->",head->value);
                head=head->next;
            }
            }
 //display all element of Stack as LL
}

int countElement()
{
    head=first;count=0;
   while(head!=NULL){

    head= head->next;
    count++;
   }
   printf("\nTotal number of Nodes are: %d",count);
   return count;
 //return the no of element in stack, can be used in pop() and push()
}
