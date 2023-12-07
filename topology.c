#include<stdio.h>
int visited[10]={0,0,0,0,0,0,0,0,0,0};
int flag=0;
#first row and first column is dummy with 0000000 s 
int adj={{0,0,0,0,0,0,0},{0,0,0,0,0,-1,-1},{0,0,0,-1,-1,0,0},{0,-1,1,0,0,0,0},{0,0,-1,1,0,0,0},{0,0,0,0,1,1,0},{0,1,0,0,0,0,1};
int check(int s,c)
	{
	  int p=s;
	  int i,f1=0;
	   if(flag==0)
	    {
	      for(i=1;i<=c;i++)
	       {
	         if(adj[p][i]==-1)
	            {
	              printf("ops invalid starting point");
	              exit(0);
	            }
	       }
	       printf("%d",&p);
	       flag=1;
	       visited[p]=1;
	    }
	  else 
	     {
	     	for(i=1;i<=c;i++)
	       {
	         if(adj[p][i]==-1 && visited[p]==0)
	            {
	              f1=-1
	              
	            }
	       }
	       if(f1==0)
	       	{
		       printf("%d",&p);
		       
		       visited[p]=1;
		       #we need to modify the insidence matrix here
		}
	     }
	}
void topo(int r,int c,int s)
	{
	  
