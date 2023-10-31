#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node *lchild;
int data;
struct node *rchild;
};
struct node *root=NULL,*neww,*r=NULL,*rt,*t1,*tp;
void create()
  {
    int v;
    neww=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to the node: ");
    scanf("%d",&v);
    neww->data=v;
    neww->lchild=NULL;
    neww->rchild=NULL;
  }
void search(struct node *rt)
{
  if(neww->data < rt->data && rt->lchild==NULL)
     rt->lchild=neww;
  else if(neww->data > rt->data && rt->rchild==NULL)
     rt->rchild=neww;
  else if(neww->data < rt->data && rt->lchild!=NULL)
     search(rt->lchild);
  else if(neww->data > rt->data && rt->rchild!=NULL)
     search(rt->rchild);
  else if(neww->data==rt->data)
     printf("\n same value has been entered twice!");
  else
     printf("\n Invalid Entry");
}
void insert()
  {
    create();
    if(root==NULL)
       root=neww;
    else
       search(root);
  }
  void deletenode(struct node *rt)
    {
     if(r==NULL)
       r=rt;
     if(rt->lchild==NULL && rt->rchild==NULL)
       {
         if(rt==r->lchild)
            r->lchild=NULL;
         else if(rt==r->rchild)
            r->rchild=NULL;
         else
             printf("\n Invalid Value");
         if(root==rt)
            root=NULL;
         free(rt);
       }
     else if(rt->lchild!=NULL && rt->rchild==NULL)
       {
         if(rt==r)
           root=rt->lchild;
         else if(rt==r->lchild)
           r->lchild=rt->lchild;
         else if(rt==r->rchild)
           r->rchild=rt->rchild;
         else
           printf("\n Invalid Value");
         free(rt);
       }
     else if(rt->lchild==NULL && rt->rchild!=NULL)
     	{
     	  if(rt==r)
     	    {
     	      root=rt->rchild;
     	    }
     	  else if(rt==r->lchild)
     	    {
     	      r->lchild=rt->rchild;
     	    }
     	  else if(rt==rt->rchild)
     	    {
     	      r->rchild=rt->rchild;
     	    }
     	  else
     	     printf("\n Invalid Value");
     	  free(rt);
     	}
     	
    else if(rt->lchild!=NULL && rt->rchild!=NULL)
      {
       t1=rt->rchild;
       if(t1->rchild!=NULL)
          {
           tp=rt;
           while(t1->lchild!=NULL)
              {
                tp=t1;
                t1=t1->lchild;
              } 
           rt->data=t1->data;
           if(t1->rchild!=NULL)
              tp->rchild=t1->rchild;
           if(tp!=rt)
             tp->lchild=NULL;
           free(t1);
             
          
          }
     else
       {
         rt->data=t1->data;
         if(t1->lchild!=NULL)
            rt->rchild=t1->lchild;
         else
            rt->rchild=NULL;
         free(t1);   
       }
          
      }  
   else
      printf("\n invalid Value");
         
       
    }
 void dsearch(struct node *rt,int dval)
{
   if(rt->data==dval) 
   {
     deletenode(rt);
   } 
else if(dval < rt->data && rt->lchild!=NULL) 
  {
    r=rt;
    dsearch(rt->lchild,dval );
  } 
 else if(dval > rt->data && rt->rchild!=NULL)
  {
    r=rt;
    dsearch(rt->rchild,dval);
  } 
 else
   printf("\nValue not found !");
}

void deletee()
  {
     int dval;
     printf("enter the node to be deleted: ");
     scanf("%d",&dval);
     if(root==NULL)
        printf("\n The BST is Empty");
     else
       dsearch(root,dval);
  }
void inorder(struct node *root)
   {
     if(root!=NULL)
       {
         
         inorder(root->lchild);
         printf("-%d-",root->data);
         inorder(root->rchild);
        }
   }     
 int main()
{
int ch;
printf("choose a Binary Search Tree operation : \n1.Insertion \n 2.Deletion \n 3.Display \n4.Exit");
while(1) {
printf("\nEnter a choice :");
scanf("%d",&ch);
switch(ch) {
case 1:
insert();
break;
case 2:
deletee();
break;
case 3:
inorder(root);
break;
case 4:
exit(0);
break;
default :
printf("invalid value");
break;
}
}
return 0;
}
