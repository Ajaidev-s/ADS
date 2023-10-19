#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node *lchild;
int data;
struct node *rchild;
};
struct node *root=NULL,*new,*r=NULL,*rt,*t1,*tp;
void create()
  {
    int v;
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to the node: ");
    scanf("%d",&v);
    new->data=v;
    new->lchild=NULL;
    new->rchild=NULL;
  }
void search(struct node *rt)
{
  if(new->data < rt->data && lchild==NULL)
     tr->lchild=new;
  else if(new->data > rt->data && rt->rchild==NULL)
     rt->rchild=new;
  else if(new->data < rt->data && rt->lchild!=NULL)
     search(rt->child);
  else if(new->data==rt->data)
     printf("\n same value has been entered twice!");
  else
     print("\n Invalid Entry");
}
void insert()
  {
    create();
    if(root==NULL)
       root=new;
    else
       search(root);
  }
  void deletenode(struct node *rt)
    {
     if(r==NULL)
       r=rt;
     if(rt->lchild==NULL && rt->rchild==NULL)
       {
         if(tr==r->rchild)
            r->lchild=NULL;
         else if(rt==r->child)
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
           root=rt->child;
         else if(rt==r->lchild)
           r->lchild=rt->child;
         else if(rt==r->rchild)
           r->rchild=rt->rchild;
         else
           printf("\n Invalid Value");
         free(rt);
       }
    else if(rt->lchild!=NULL && rt->rchild!=NULL
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
          
      }  
         
       
    }
