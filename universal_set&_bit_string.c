#include<stdio.h>
#include<conio.h>
void main()
    {   int m,n,i,j,flag;
        int uni[15],a[15],b[15];
       int bit_uni[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
       int bit_a[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
       int bit_b[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        printf("\nenter the no of elements in the universal set: ");
        scanf("%d",&m);
        printf("enter the elements\n");
        //universal set elements
        for(i=0;i<m;i++)
            {
                scanf("%d",&uni[i]);
            }
        printf("\nenter the no of elements in set B : ");
        scanf("%d",&n);
        printf("enter the elements\n");
        //insertion of elements as well as creation of bit string
        for(j=0;j<n;j++)
          {
            scanf("%d",&b[j]);
            flag=0;
            //for loop to search if the element exist in universal set
            for(i=0;i<m;i++)
               {
                  if(b[j]==uni[i])
                    {
                        flag=1;
                        bit_b[i]=1;
                    }
               }
            if(flag==0)
                {
                    printf("\n oops the element not present in universal set,plz re-enter data");
                    j--;
                }
          }
    printf("\nThe bit string of set b is :\n");
    //to print bitstring
    for(i=0;i<m;i++)
        {
            printf("%d ",bit_b[i]);
        }
    getch();

    }