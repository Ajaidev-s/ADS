#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
 struct node *prev;
};

struct node *head=NULL;
struct node *end=NULL;



void ins_strt()
{
 struct node *temp;
 int data;
 printf("\nEnter the element to add:");
 scanf("%d",&data);
 temp=(struct node *)malloc(sizeof(struct node));
 temp->data=data;
 temp->next=head;
 temp->prev=NULL;
 if(head==NULL)
 {
   end=temp;
 }
 else
 { 
   
   head->prev=temp;
   
 }
  head=temp;
}


void ins_end()
{
 int data;
 struct node *temp,*ptr;
 temp=(struct node *)malloc(sizeof(struct node));
 ptr=head;
 printf("\nEnter the element to add:");
 scanf("%d",&data);

 temp->data=data;
 temp->next=NULL;
 end=temp;
 if(head==NULL)
 {
  temp->prev=NULL;  
  head=temp;
 }
 else
 {
  while(ptr->next!=NULL)
  {
   ptr=ptr->next;
  }
  ptr->next=temp;
  temp->prev=ptr;
 }

}


void display()
{
 struct node *ptr;
 ptr=head;
 if(head==NULL)
 { 
  printf("\nlinked list is empty");
 }
 else
 {
 
 while(ptr->next!=NULL)
 { 
  printf("\n%d",ptr->data);
  ptr=ptr->next;
 }
 printf("\n%d",ptr->data);
 }
}

void disp_rev()
{ 
 struct node *ptr;
 ptr=end;
 if(ptr==NULL)
 {
 printf("\n list is empty");
 }
 else
 {
  while(ptr->prev!=NULL)
  {
  printf("\n%d",ptr->data);
  ptr=ptr->prev;
  }
  printf("\n%d",ptr->data);
 }
}


void dlt_strt()
{
 struct node *temp,*dlt;
 dlt=head;
 if(dlt==NULL)
 {
  printf("\nempty");
 }
 else
 {
  head=dlt->next;
  head->prev=NULL;
  printf("%d is deleted",dlt->data);
  free(dlt);
 }
 
}


void dlt_end()
{
 struct node *ptr;
 ptr=end;
 
 if(ptr==NULL)
 {
  printf("\nempty");
 }
 else
 {
  end=ptr->prev;
  end->next=NULL;
  printf("\n%d is deleeted",ptr->data);
  free(ptr);
 }
 
}

void ins_pos()
{ 
 int data,pos,i;
 struct node *temp,*ptr,*nexxt,*swap;
 printf("Enter the value to input:");
 scanf("%d",&data);
 printf("\nEnter the position:");
 scanf("%d",&pos);
 temp=(struct node *)malloc(sizeof(struct node));
 temp->data=data;
 temp->next=NULL;
 if(head==NULL)
 { 
  head=temp;
  temp->prev=NULL;
  temp->next=NULL;
  end=temp;
 }
 else
 {
  ptr=head;
  for(i=1;(i<pos-1)&&(ptr->next!=NULL);i++)
  {
   printf("\n%d",ptr->data);
   ptr=ptr->next;
  
  }
  if(ptr==head && i==(pos))
  {
  ptr->prev=head;
  temp->next=ptr;
  temp->prev=NULL;
  head=temp;
  }
  else if(ptr==end && i==(pos-1))
  {
   ptr->next=temp;
   temp->prev=ptr;
   end=temp;
  }
  else if(i==(pos-1))
  {
  nexxt=ptr->next;
  swap=ptr->next;
  temp->next=swap;
  nexxt->prev=temp;
  ptr->next=temp;
  }
  else
  {
  printf("\nInvalid");
  }
 }
}


void dlt_pos()
{
 struct node *ptr,*previous,*nexxt;
 int pos;
 printf("\nEnter the position:");
 scanf("%d",&pos);
 ptr=head;
 if(head==NULL)
 { 
  printf("\nlinked list is empty");
 }
 else
 {
  int i=1;
  while(ptr->next!=NULL && i!=pos)
  {
   ptr=ptr->next;
   i++;
  }
  if(ptr==head && i==pos)
  {
   head=ptr->next;
   head->prev=NULL;
   free(ptr);
  }
  else if(ptr==end && i==pos)
  {
   end=ptr->prev;
   end->next=NULL;
   free(ptr);
  }
  else if(i==pos)
  {
  previous=ptr->prev;
  nexxt=ptr->next;
  previous->next=nexxt;
  nexxt->prev=previous;
  }
  else
  printf("\nInvalid");
 }
}
 
void search()
{
 int data,i;
 struct node *ptr;
 ptr=head;
 if(head!=NULL)
    {
 	printf("Enter element to search:");
	 scanf("%d",&data);
 	for(i=1;ptr!=end;i++)
 	{
	  if(ptr->data==data)
 	 { 
  	 printf("\nelement found at position %d",i);
 	 }
 	 ptr=ptr->next;
  
	 }
	if(ptr->data==data)
 	 { 
  	 printf("\nelement found at position %d",i);
 	 }
	 
    }
  else
  	printf("The list is empty");
}


int main()
{
 int ch;
 do
 {
  printf("\n1.insert at start \n2.insert at end \n3.insert at position \n4.display \n5.display in reverse \n6.delete at start \n7.delete at end \n8.delete at pos \n9.search an element \n10.exit \nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:ins_strt();
          break;
   case 2:ins_end();
          break;
   case 3:ins_pos();
   	  break;
   case 4:display();
          break;
   case 5:disp_rev();
          break;
   case 6:dlt_strt();
   	  break;
   case 7:dlt_end();
          break;
   case 8:dlt_pos();
          break;
   case 9:search();
          break;
   case 10:exit;
          break;
   default:("\nInvalid position");
  }

   
 }  while(ch!=9);
 return 0;
}
          
