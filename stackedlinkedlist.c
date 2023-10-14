#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
      {
	 int data;
	 struct node *next;

      };
struct node *head=NULL;
//function to insert
struct node dummy;
void push()
     {  int data;
	struct node *temp;
	printf("\nenter the value to input : ");
	scanf("%d",&data);
	temp=(struct node*)malloc(sizeof(dummy));
	temp->data=data;
	temp->next=head;
	head=temp;
     }
void display()
     {
	int i=1;
	struct node *ptr;
	ptr=head;
	if(ptr!=NULL)
	  {
	    while(ptr!=NULL)
	      {
	       printf("%d th element\t %d \n",i,ptr->data);
	       ptr=ptr->next;
	       i++;
	      }
	  }
	else
	   {
	     printf("\n stack is empty \n");
	   }
     }
void pop()
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
		    printf("stack underflow") ;
	}
void search()
     {
	int i=1,item;
	struct node *ptr;
	ptr=head;
	if(ptr!=NULL)
	  {
		printf("enter the element to search");
		scanf("%d",&item);
	    while(ptr!=NULL)
	      {
		   if(ptr->data==item)
		   	{
               printf("%d found at position \t %d from top of the stack\n",ptr->data,i);
			}
	       ptr=ptr->next;
	       i++;
	      }
	  }
	else
	   {
	     printf("\n stack is empty \n");
	   }
     }		 
int main()
    {
	int choice;
	do{
	    printf("\n1.push\n2.pop\n3.display\n4.search\n5.exit");
	    printf("\n\nEnter your choice");
	    scanf("%d",&choice);
	    switch(choice)
		{
		    case 1 : push();
			     break;

		    case 2 : pop();
			     break;
		    case 3 : display();
			     break;	
			case 4: search();
				 break;	 
		    case 5 : printf("exiting");
			     break;
		    default : printf("Invalid choice .if you want to exit pls enter 5 as choice");

		}
	}while(choice!=5);
	getch();
	return 0;
    }
