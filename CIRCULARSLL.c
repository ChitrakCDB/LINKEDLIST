#include<stdio.h>
#include<memory.h>
//Linked List
typedef struct{
    int no;
    struct node *next;
}node;
node *first='\0',*head='\0',*temp='\0';
//Function Declaration
void printMenu();
void createLL(int);
void insertNode();
void searchNode(int);
void updateNode(int,int);
void deleteNode(int);
void deleteLL();
void printLL();
int main(){
int choice,noOfNode,valueOfNode,searchValue,newValue;
    do{
        printMenu();
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nHow many node(s) do you want to enter : ");
                scanf("%d",&noOfNode);
                createLL(noOfNode);
                break;
            case 2:
                insertNode();
                break;
            case 3:
                printf("\nEnter the value to be searched: ");
                scanf("%d",&valueOfNode);
                searchNode(valueOfNode);
                break;
            case 4:
                printf("\nEnter the value to be updated: ");
                scanf("%d",&searchValue);
                printf("\nEnter the value to be placed in that node: ");
                scanf("%d",&newValue);
                updateNode(searchValue,newValue);
                break;
         case 5:
                printf("\nEnter value to be deleted: ");
                scanf("%d",&valueOfNode);
                deleteNode(valueOfNode);
                break;
            case 6:
                deleteLL();
                break;
             case 7:
                printLL();
                break;
            default:
                printf("Thanks for Using LL program.");
        }
    }while(choice>0 && choice<8);
    return 0;
}
//Implementation of Function
void printMenu(){
    system("cls");
    printf("\n========================================");
    printf("\n           LL OPERATION MENU            ");
    printf("\n========================================");
    printf("\n1.Create LL");
    printf("\n2.Insert node");
    printf("\n3.Search node");
    printf("\n4.Update Node");
    printf("\n5.Delete node");
    printf("\n6.Delete LL");
    printf("\n7.Print LL");
    printf("\n8.Exit");
    printf("\n========================================\n");
}
void createLL(int noOfNode){
    while(noOfNode>0){
        insertNode();
        noOfNode--;
    }
}
void insertNode(){
//Create new node
    temp = (node *)malloc(sizeof(node)*1);
        printf("\nEnter value for new node: ");
        scanf("%d",&temp->no);
        temp->next = '\0';
        //Attach the node in linked list
        if(first == '\0'){
            first = temp;
            temp->next = first;
        } else {
            head = first;
            while(head->next!=first){
                head = head->next;
            }
            head->next = temp;
            temp->next = first;
        }
        getch();
}
void searchNode(int valueOfNode){
    int position = 0,flag = 0;
    head = first;
    printf("\nNode %d - ",valueOfNode);
    do{
        if(head->no == valueOfNode){
            printf("%d",position+1);
            flag =1;
        }
        head = head->next;
        position++;
    }while(head!=first);
    if(flag == 0){
        printf("not found in the LL");
    } else {
        printf("\n Found at above position(s)");
    }
    getch();
}
void updateNode(int searchValue,int newValue){
    int position = 0,flag = 0;
    head = first;
    printf("\nNode %d - ",searchValue);
    do{
        if(head->no == searchValue){
            head->no = newValue;
            printf("%d ",position+1);
            flag =1;
        }
        head = head->next;
        position++;
    }while(head!=first);
    if(flag == 0){
        printf("not found in the LL");
    } else {
        printf("\n Found at above position(s)");
    }
}
void deleteNode(int valueOfNode){
    head = first;
    do
    {
        temp=head->next;
        if(head->no == valueOfNode)
        {
            temp=head;
            while(head->next!=first){
                head=head->next;
            }
            head->next=temp->next;
            first = first->next;
            free(temp);
            head=head->next;
        }
        else if(temp->no == valueOfNode)
        {
            head->next=temp->next;
            if(temp==first){
                first=first->next;
            }
            free(temp);
        }
        else
        {
            head = head->next;
        }
    }while(head->next != first);
    if(first->no==valueOfNode && first->next==first){
        temp = head;
        head=NULL;
        first=NULL;
        free(first);
    }
    getch();
}
void deleteLL(){
    while(first->next!=first){
        temp = first->next;
        first->next = temp->next;
        free(temp);
    }
    free(first);
    first=NULL;
}
void printLL(){
    if(first==NULL){
        printf("Linked List is empty nothing to print....");
    } else {
        head=first;
        do{
            printf("%d -> ",head->no);
            head = head->next;
        }while(head!=first);
    }
    getch();
}
