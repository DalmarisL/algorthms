#include<stdio.h>

#define MAX 30

typedef struct edge
{
    int u, v, w;
} edge;

typedef struct edgelist
{
    edge data[MAX];
    int n;
} edgelist;

edgelist e_list;

int G[MAX][MAX], n;
edgelist spa_list;

void kruskal();
int find(int belongs[], int vertex);
void union_(int belongs[], int d1, int d2);
void sort();
void print();


void kruskal()
{
    int belongs[MAX], i, j, cn1,cn2;
    e_list.n = 0;

    for(i=1; i<n; i++)
        for(j=0; j<i; j++)
        {
            if(G[i][j] != 0)
            {
                e_list.data[e_list.n].u = i;
                e_list.data[e_list.n].v = j;
                e_list.data[e_list.n].w = G[i][j];
                e_list.n++;
            }
        }

        sort();

        for(i=0; i<n; i++)
            belongs[i] = i;

        spa_list.n = 0;

        for(i=0; i<e_list.n; i++)
        {
            cn1 = find(belongs, e_list.data[i].u);
            cn2 = find(belongs, e_list.data[i].v);

            if(cn1 != cn2)
            {
                spa_list.data[spa_list.n] = e_list.data[i];
                spa_list.n = spa_list.n+1;
                union_(belongs, cn1, cn2);
            }
        }
}

int find( int belongs[], int vertex)
{
    return(belongs[vertex]);
}

void union_(int belongs[], int d1, int d2)
{
    int i;

    for(i=0; i<n; i++)
        if(belongs[i] == d2)
            belongs[i] = d1;
}

void sort()
{
    int i, j;
    edge temp;

    for(i=1; i<e_list.n; i++)
        for(j=0; j<e_list.n-1; j++)
            if(e_list.data[j].w > e_list.data[j+1].w)
            {
                temp = e_list.data[j];
                e_list.data[j] = e_list.data[j+1];
                e_list.data[j+1] = temp;
            }
}


void print()
{
    int i, cost = 0;

    for(i=0; i<spa_list.n; i++)
        cost = cost + spa_list.data[i].w;
    printf("\n\nCost of the spanning tree=%d",cost);
}


void main()
{
    int i, j;
    printf("\nN° verteces: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        scanf("%d", &G[i][j]);

    kruskal();
    print();


}


