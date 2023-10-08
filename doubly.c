#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
      {
	 int data;
	 // creating a node(struct) pointer to point next element of linked list;
	 struct node *next;
     struct node *prev;

      };
//creating pointer head of type node(struct) to save the starting address of the linked list .since starting there are no elements in linked list its assigned with NULL
struct node *head=NULL,*end=NULL;
//function to insert
struct node dummy;
void ins_strt()
     {  int data;
	struct node *ptr,*temp;
	printf("\nenter the value to input : ");
	scanf("%d",&data);
	//creating a node and saving its address in temp
	temp=(struct node*)malloc(sizeof(dummy));
	//setting the data element in temp user input
	temp->data=data;
	//setting next pointer in temp with head adress of current linkedlist .To make temp as first element
	temp->next=head;
    temp->prev=NULL;
    if(head==NULL)
        end=temp;
	//now temp has the adress of first element in current linkedlist.so we asign that adress to head
    head->prev=temp;
	head=temp;
     }
void ins_end()
     {
	int data;
	struct node *ptr,*temp;
	printf("\nenter the value to input : ");
	scanf("%d",&data);
	 temp=(struct node*)malloc(sizeof(dummy));
	  temp->data=data;
	  temp->next=NULL;
      end=temp;

	  //if the linkedlist is empty .then temp has the adress of the first element so we asign the adress to head
	if(head==NULL)
	  {
        temp->prev=NULL;
	    head=temp;
        
	  }
	else
	  {
	    ptr=head;
	    //to find the last element in linked list we go trough the linked list until we find the pointer with null which indicate the last element
	    while(ptr->next!=NULL)
		{
		    ptr=ptr->next;
		}
	    //then we asign the adress of new now(temp) to the pointer of last not which means the new node is connected to last node
	    ptr->next=temp;
        temp->prev=ptr;

		
	  }
     }
void display()
     {
	int i=1;
	struct node *ptr;
	ptr=head;
	if(ptr!=NULL)
	  {
	    while(ptr->next!=NULL)
	      {
	       printf("%d th element\t %d \n",i,ptr->data);
	       ptr=ptr->next;
	       i++;
	      }
	    printf("%d th element\t %d \n",i,ptr->data);
	  }
	else
	   {
	     printf("\n linked list is empty \n");
	   }
     }
void dlt_strt()
	{
		struct node *dlt;
		dlt=head;
		if(dlt!=NULL)
		  {
			head=dlt->next;
			printf("\n deleted element is %d \n",dlt->data);
			free(dlt);
		  }
		 else
		    printf("the linked list is empty") ;
	}
void dis_from_end()
    {
       int i=1;
	struct node *ptr;
	ptr=end;
	if(ptr!=NULL)
	  {
	    while(ptr->prev!=NULL)
	      {
	       printf("%d th element\t %d \n",i,ptr->data);
	       ptr=ptr->prev;
	       i++;
	      }
	    printf("%d th element\t %d \n",i,ptr->data);
	  }
	else
	   {
	     printf("\n linked list is empty \n");
	   }

 
    }
int main()
    {
	int choice;
	do{
	    printf("\n1.add at start\n2.add at end\n3.display\n4.display from end \n10.exit");
	    printf("\n\nEnter your choice");
	    scanf("%d",&choice);
	    switch(choice)
		{
		    case 1 : ins_strt();
			     break;

		    case 2 : ins_end();
			     break;
		    case 3 : display();
			         break;
            case 4:dis_from_end();
                    break;

             case 10 : printf("exiting");
			     break;
		    default : printf("Invalid choice .if you want to exit pls enter 5 as choice");

		}
	}while(choice!=10);
	getch();
	return 0;
    }