#include<stdio.h>

#define infinity 9999
#define MAX 30


void dijkstra(int G[MAX][MAX], int n, int st_node)
{
    int cost[MAX][MAX], dist[MAX], pred[MAX];
    int vist[MAX], count, min_dist, next_node, i, j;


    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(G[i][j] == 0)
                cost[i][j] = infinity;
            else
                cost[i][j] = G[i][j];

    for(i=0; i<n; i++)
    {
        dist[i] = cost[st_node][i];
        pred[i] = st_node;
        vist[i] = 0;
    }

    dist[st_node] = 0;
    vist[st_node] = 1;
    count = 1;

    while(count < n-1)
    {
        min_dist = infinity;

        for(i=0; i<n; i++)
            if(dist[i] < min_dist &&! vist[i])
            {
                min_dist = dist[i];
                next_node = i;
            }

            vist[next_node] = 1;
            for(i=0; i<n; i++)
                if(!vist[i])
                    if(min_dist + cost[next_node][i] < dist[i])
                    {
                        dist[i] = min_dist + cost[next_node][i];
                        pred[i] = next_node;
                    }

        count++;
    }

    for(i=0; i<n; i++)
        if(i != st_node)
        {
            printf("\nDistance of node %d = %d", i, dist[i]);
            printf("\nPath = %d", i);

            j=i;

            do
            {
                j=pred[j];
                printf("< %d", j);
            }
            while(j != st_node);
        }

}

int main()
{
    int G[MAX][MAX], i, j, n, u;
    printf("\nN° of verteces: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d", &G[i][j]);

    printf("\nEnter the starting node:");
    scanf("%d", &u);

    dijkstra(G,n,u);

    return 0;
}
