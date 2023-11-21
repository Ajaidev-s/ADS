#include <stdio.h>
#include <limits.h>

#define MAX 20

void prim(int n, int cost[MAX][MAX], int t[MAX - 1][2]) {
    int near[MAX];
    int min = INT_MAX;
    int u, v;

    // Initialize near array and t array
    for (int i = 1; i < n; i++) {
        near[i] = 0;
    }

    // Start with the first vertex
    near[0] = 1;

    // Loop through n-1 times to find n-1 edges
    for (int i = 1; i < n; i++) {
        // Find the minimum cost edge
        min = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (near[j] != 0) {
                for (int k = 0; k < n; k++) {
                    if (near[k] == 0 && cost[j][k] < min) {
                        u = j;
                        v = k;
                        min = cost[j][k];
                    }
                }
            }
        }

        // Store the edge in the result array t
        t[i - 1][0] = u;
        t[i - 1][1] = v;
        near[v] = 1;
    }
}

int main() {
    int n, cost[MAX][MAX], t[MAX - 1][2];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Call the Prim's algorithm function
    prim(n, cost, t);

    // Display the minimum spanning tree
    printf("Minimum Spanning Tree Edges:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("(%d, %d)\n", t[i][0] + 1, t[i][1] + 1);
    }

    return 0;
}
