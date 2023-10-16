#include<stdio.h>
int main()
{
    int n,i,a[100],item,flag=0;
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter the element to search:");
    scanf("%d",&item);
    for(i=0;i<n;i++)
    {
        if(a[i]==item)
        {
            printf("\nitem found at position %d",i+1);
            flag=1;
            break;
        }
        
    }
    if(flag==0)
    {
        printf("\nUnsuccessfull search\n");
    }
    return 0;
}

