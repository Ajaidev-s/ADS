#include <stdio.h>
#include <stdlib.h>

#define MAX 30

int parent[MAX];

typedef struct {
    int u, v, w;
} Edge;

int find(int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void union_(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int compare(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

void kruskal(int V, int E, Edge edges[],int t[V-1][3]) {
    int i, u, v,j=0;
    int mincost = 0;

    for (i = 0; i < V; i++) {
        parent[i] = i;
    }

    qsort(edges, E, sizeof(Edge), compare);

 

    for (i = 0; i < E; i++) {
        u = edges[i].u;
        v = edges[i].v;
        if (find(u) != find(v)) {
            //matrix to represent minimum cost spanning tree
            //u+1 to adjust vertices to be 1-based
               t[j][0]=u;
               t[j][1]=v;
               t[j][2]=edges[i].w;
               j++;
            mincost += edges[i].w;
            union_(u, v);
        }
    }

    printf("Total Weight of the Minimum Spanning Tree: %d\n", mincost);
}

int main() {
    int V, E, i;
    printf("Enter the number of vertices and edges (V E): ");
    scanf("%d %d", &V, &E);
    int t[V-1][3];

    Edge edges[MAX];

    printf("Enter the edges and weights (u v w) one by one:\n");
    for (i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        
    }

    kruskal(V,E,edges,t);
    printf("The minimumcost spaning tree have the following edges\nv1\tv2\tw");
    for(i=0;i<V-1;i++)
    {
       printf("\n%d\t%d\t%d",t[i][0],t[i][1],t[i][2]);
    }

    return 0;
}
