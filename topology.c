#include<stdio.h>
int main()
    {
      int adj[10][10],v,i,j,k,visited[10]={0,0,0,0,0,0,0,0,0,0},flag,visit,count=0;
      printf("\nEnter the no of vertices\n");
      scanf("%d",&v);
      printf("\nEnter the adjacency matrix\n");
      //accepting the adjacency matrix
      for(i=1;i<=v;i++)
        {
            for(j=1;j<=v;j++)
                {
                    scanf("%d",&adj[i][j]);
                }
        }
        //this for loop is to continues the loop until all the vertex have been visited
    for(visit=0;visit<v;)
        {   count++;
            if(count>100)
               {
                printf("ops the graph contain a cycle \n .......exiting......\n");
                return 0;
               }
             for(i=1;i<=v;i++)
                 {  
                     
                     //we only check if the vertex isnt visited alreadddy
                     if(visited[i]!=1)
                        {   
                            //flag is very importent to check if the adjacency matrix has all zero in a column ,which represent no incoming edge 
                            flag=0;
                             for(j=1;j<=v;j++)
                                {
                                   if(adj[j][i]==1)
                                     {
                                        // this only execute if and only if that column have a 1 ,which means an incoming edge
                                        flag=1;
                                     }
                                }
                             //if the flag is 0 .means no incoming edge. so it is printed
                            if(flag==0)
                                {
                                    printf("%d->",i);
                                    visited[i]=1;
                                    visit++;
                                    //making the printed elements row all zero.logically deleting the vertex
                                    for(k=1;k<=v;k++)
                                        {
                                            adj[i][k]=0;
                                        }
                                }
                        }
                     
                 }
        }
      
    return 0;
    }
