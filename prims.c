#include<stdio.h>
int main()
    {
        int t[4][2];
        int near[5];
        int n=5,j;
        int cost[5][5]={{999,5,8,999,999},{5,999,999,3,4},{8,999,999,6,999},{999,3,6,999,2},{999,4,999,2,999}};
        int mincost=cost[4][3];
        int min=999,min_j;
        //the vertices are 5 and for but in matrix start from 0
        int k=4,l=3,i;
        //since the vertixes are 5 and 4 respectively
        t[0][0]=k+1;
        t[0][1]=l+1;
        for(i=0;i<n;i++)
        {
            if(cost[i,l]<cost[i,k])
                near[i]=l;
            else
                near[i]=k;
            
        }
        near[k]=near[l]=0;
        printf("near of after first iteration \n");
        for(i=0;i<n;i++)
            printf("%d \t",near[i]);
        //here near[]={3,3,3,0,0}
        for(i=1;i<n-1;i++)
            {
                //to find j such that near[j]!=0 and cost[j,near[j]] is minimum
                for(j=0;j<n;j++)
                {
                   if(near[j]!=0 && min>cost[j][near[j]])
                   {
                     min=near[j];
                     min_j=j;
                     //since both are same we remove a value 
                    
                   }
                }
                min=999;
                j=min_j;
                printf("minimumcost in %d th iteration %d \n",i,cost[j][near[j]]);
                t[i][0]=j+1;
                t[i][1]=near[j]+1;
                mincost=mincost+cost[j][near[j]];
                near[j]=0;
                for(k=2;k<n;k++)
                  {
                  if(near[k]!=0&& (cost[k][near[k]]>cost[k][j]))
                      near[k]=j;
                  }
            }
          printf("minimumcost=%d \n",mincost);
          for(j=0;j<n-1;j++)
          	{
          	printf("%d \t %d \n",t[j][0],t[j][1]);
          	}
          return 0;


    }
