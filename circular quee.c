#include<conio.h>
#include<stdio.h>
int front=-1,rear=-1,max,item;
int cquee[20];
void insert();
void delection();
void search();
void display();
int main()
    {
        int choice;
        printf("enter the size of quee");
        scanf("%d",&max);
        do{
            printf("\n1.insertion\n2.delection\n3.search\n4.display\n5.exit");
            scanf("%d",&choice);
            switch(choice)
                {
                    case 1:insert();
                           break;
                    case 2:delection();
                           break;
                    case 3:search();
                           break;
                    case 4:display();
                           break;
                    case 5:printf("exiting");
                           break;
                    default:printf("\nif u want to exit please enter 4\n");
               }
        
          }while(choice!=5);

    }
void insert()
{
    int temprear=rear;
     printf("\n rear=%d",rear);
     rear=(rear+1)%(max);
     printf("\n rear=%d",rear);
     printf("\n max= %d",max);
     printf("\nfront=%d",front);
    if(front==-1)
        {
           front=0;
           rear=0;
           printf("enter the element to insert: ");
           scanf("%d",&item);
           cquee[rear]=item;
        }
    else if(rear==front)
        {
            printf("quee overflow");
            rear=temprear;

        }
    else
        {  
            //  rear=(rear+1)%(max-1);
            printf("enter the element to insert: ");
            scanf("%d",&item);
            cquee[rear]=item;
        }
}

void display()
    {
        int i=front;
        printf("front=%d \n rear=%d",front,rear);
        if(front==-1)
            {
                printf("quee is empty");
            }
        else
            {
                for(;i!=rear;i=((i+1)%(max)))
                {
                    printf("\n %d ",cquee[i]);
                }
                 printf("\n %d ",cquee[i]);
            }
    }
void delection()
    {
        if(front==-1)
        {
            printf("\nquee underflow\n");
        }
        else if(front==rear)
            {
                printf("\ndelecting element %d",cquee[front]);
                front=-1;
                rear=-1;
            }
        else
            {   front=(front+1)%max;
                printf("\n delecting the element %d",cquee[front]);
            }
    }
void search()
    {
        int data,i=1,dfront=front;
        printf("enter the element to search");
        scanf("%d",&data);
        if(front==-1)
            {
                printf("quee is empty");
            }
        else
            {
                for(;dfront!=rear;dfront=((dfront+1)%(max)))
                {
                    if(cquee[dfront]==data)
                        {
                            printf("element fount at %d th position",i);
                        }
                    i++;
                }
                  if(cquee[dfront]==data)
                        {
                            printf("element fount at %d th position",i);
                        }
            }
    }