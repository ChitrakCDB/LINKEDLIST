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
void sort();
void displayQueue();
int countElement();

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
                sort();
                displayQueue();
                break;

            case 4:
                if(COUNT>0)
                {
                    displayQueue();
                }
                else
                {
                    printf("\n Queue is Empty");
                }
                break;

            case 5:
                printf("\n No of Element in Queue : %d",countElement());
                break;

            default:
                printf("Thanks for Using Queue Program");
        }

        getch(); //To stop output on Screen
    }
    while(choice>0 && choice<5);
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
    printf("\n     3 - SORT");
    printf("\n     4 - DISPLAY");
    printf("\n     5 - SIZE");
    printf("\n     0 - EXIT");
    printf("\n==============================");
}

void enqueue(int value,int priority)
{
    temp=(struct Element *)malloc(sizeof(struct Element)*1);
    temp->value=value;
    temp->priority=priority;
    temp->next=NULL;
    printf("\n IN Function");

    if(FRONT==NULL)
    {
        FRONT=temp;
        REAR=temp;
        printf("\n IN NULL");
    }

    else
    {
        REAR->next=temp;
        REAR=temp;
    }
}

void dequeue()
{
    temp=FRONT;
    FRONT=FRONT->next;
    free(temp);
}

void sort()
{
    head=FRONT;
    while(head->next!='\0')
    {
        temp=head->next;
        while(temp!='\0')
        {
            if(head->priority < temp->priority)
            {
                temp->value = head->value+temp->value;
                head->value = temp->value-head->value;
                temp->value = temp->value-head->value;

                temp->priority = head->priority+temp->priority;
                head->priority = temp->priority-head->priority;
                temp->priority = temp->priority-head->priority;
            }
            temp = temp->next;
        }
        head = head->next;
    }
    head = FRONT;
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
