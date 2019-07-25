#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
//Linked List
struct node{
   int no;
   struct node *next;
};
struct node *first='\0',*fhead='\0',*temp='\0',*second=NULL,*shead=NULL,*head=NULL;
//Function Declaration
void printMenu();
struct node * createLL(struct node *,int);
struct node * copyLL(struct node *);
void printLL(struct node *);
void concatLL(struct  node *,struct node *);


int main(){

   int choice,noOfNode,valueOfNode,searchValue,newValue;
   do{
       printMenu();
       printf("Enter your choice : ");
       scanf("%d",&choice);
       switch(choice){
           case 1:
               printf("\n Enter How Many Nodes You Want in first LL : ");
               scanf("%d",&noOfNode);
               first=createLL(fhead,noOfNode);
               printf("\n Enter How Many Nodes You Want in Second LL : ");
               scanf("%d",&noOfNode);
               second=createLL(shead,noOfNode);

               break;

           case 2:
               fhead=first;
               second = copyLL(fhead);
               break;

           case 3:
                  fhead=first;
                  shead=second;
                  concateLL(fhead,shead);
               break;

           case 4:

               break;

           case 5:

               break;

           case 6:

               break;

           case 7:
               printf("\nFirst LinkedList Data : ");
               fhead=first;
               printLL(fhead);

               printf("\nSecond LinkedList Data : ");
               shead=second;
               printLL(shead);

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
   printf("\n2.Copy LL");
   printf("\n3.Concate LL");
   printf("\n4.Reverse LL");
   printf("\n5.Split LL");
   printf("\n6.Count Node(s) in LL");
   printf("\n7.Print LL");
   printf("\n8.Exit");
   printf("\n========================================\n");

}

struct node * createLL(struct node * first,int noOfNode){
   while(noOfNode>0){
       //Create new node
       temp = (struct node *)malloc(sizeof(struct node)*1);
       printf("\nEnter value for new node: ");
       scanf("%d",&temp->no);
       temp->next = NULL;

       //Attach the node in linked list
       if(first == '\0'){
           first = temp;
       } else {
           head = first;
           while(head->next!=NULL){
               head = head->next;
           }
           head->next = temp;
       }
       noOfNode--;
   }
   return first;
}

struct node * copyLL(struct node * shead){
    struct node *first =NULL;
    while(shead!=NULL){
       //Create new node
       temp = (struct node *)malloc(sizeof(struct node)*1);
       temp->no=shead->no;
       temp->next = NULL;

       //Attach the node in linked list
       if(first == '\0'){
           first = temp;
       } else {
           head = first;
           while(head->next!=NULL){
               head = head->next;
           }
           head->next = temp;
       }
      shead=shead->next;
   }
   return first;
}

void concateLL(struct node *fhead,struct node *shead){
   struct node *head=NULL;
   head = first;
   while(fhead->next!=NULL){
       fhead=fhead->next;
   }
   while(shead!=NULL){
       //Create new node
       temp = (struct node *)malloc(sizeof(struct node)*1);
       temp->no=shead->no;
       temp->next = NULL;
      //Attach the node in linked list
      fhead->next=temp;
      fhead=temp;
    shead=shead->next;
        }

}

void printLL(struct node *first){
   head=first;
   while(head!=NULL){
       printf("%d -> ",head->no);
       head = head->next;
   }
   getch();
}
