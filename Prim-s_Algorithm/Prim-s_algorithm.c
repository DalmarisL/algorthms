#include<stdio.h>
#include<stdlib.h>


#define infinity 9999
#define MAX 30


int G[MAX][MAX], spa[MAX][MAX], n;
int prim();


int prim()
{
    int cost[MAX][MAX];
    int u, v, min_dis, dis[MAX], from[MAX];
    int vis[MAX], n_edges, i, min_cost,j;

    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            if(G[i][j] == 0)
                cost[i][j] = infinity;
            else
                cost[i][j] = G[i][j];
            spa[i][j] = 0;
        }

        dis[0] = 0;
        vis[0] = 1;

        for(i=1; i<n; i++)
        {
            dis[i] = cost[0][i];
            from[i] = 0;
            vis[i] = 0;
        }

        min_cost = 0;
        n_edges = n-1;

        while(n_edges > 0)
        {

            min_dis = infinity;
            for(i=1; i<n; i++)
                if(vis[i] == 0 && dis[i] < min_dis)
                {
                    v = i;
                    min_dis = dis[i];
                }


            u = from[v];

            spa[u][v] = dis[v];
            spa[v][u] = dis[v];
            n_edges--;
            vis[v] = 1;

            for(i=1; i<n; i++)
                if(vis[i] == 0 && cost[i][v] < dis[i])
                {
                    dis[i] = cost[i][v];
                    from[i] = v;

                }
                min_cost = min_cost + cost[u][v];
        }

        return(min_cost);
}


int main()
{
    int i, j, tCost;
    printf("N° of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix: \n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", &G[i][j]);

    tCost=prim();

    printf("\n\nTotal cost of spanning tree=%d", tCost);
    return 0;

}
