void prims(E,cost,n)
    {
        int t[4][2];
        int near[6]
        int cost[5][5]={{999,5,8,999,999},{5,999,999,3,4},{8,999,999,6,999},{999,3,6,999,2},{999,4,999,2,999}};
        int mincost=cost[4][3];
        //the vertices are 5 and for but in matrix start from 0
        int k=4,l=3,i;
        //since the vertixes are 5 and 4 respectively
        t[1][1]=k+1;
        t[1][2]=l+1;
        for(i=0,i<n;i++)
        {
            if(cost[i,l]<cost[i,k])
                near[i]=l;
            else
                near[i]=k;
            near[k]=near[l]=0;
        }
        
        for(i=1;i<n-1;i++)
            {
                for(j=0;j<n;j++d)
            }


    }