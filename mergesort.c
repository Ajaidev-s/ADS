#include<conio.h>
#include<stdio.h>
void main()
    {   int m,n,p;
        int i,j,k;
        int a[20],b[20],c[40];
        printf("enter the no of elements in the first array: ");
        scanf("%d",&m);
        printf("enter the elements: ");
        for(i=0;i<m;i++)
            {
                scanf("%d",&a[i]);
            }
        printf("enter the no of elements in the 2nd array: ");
        scanf("%d",&n);
        printf("enter the elements: ");
        for(i=0;i<n;i++)
            {
                scanf("%d",&b[i]);
            }
        p=m+n;

        //sorting starts here
        i=0;
        j=0;
        
        for(k=0;k<p;k++)
            {
               if(a[i]<b[j] && i<m)
                {
                    c[k]=a[i];
                    i++;
                }
               else if(j<n)
                  {
                    c[k]=b[j];
                    j++;
                  }
                else
                    {
                        c[k]=a[i];
                        i++;
                    }
            }
        //sort ended

    //code to print the merged array
    printf("\nmerged array is\n");
       for(i=0;i<p;i++)
          {
             printf("%d\n",c[i]);
          }
    getch();
    }
