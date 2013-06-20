#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
struct Edge
{
    int src, dest, weight;
};
struct Graph
{
   int V, E;
   struct Edge* edge;
};
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) ); 
    return graph;
}
void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
        dist[i]   = INT_MAX;
    dist[src] = 0;
    for (int i = 1; i <= V-1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle");
    }
 
    printArr(dist, V);
    return;
}
int main()
{
    int V = 5;  
    int E = 8; 
    int i;
    struct Graph* graph;
    printf("Enter number of nodes : ");
    scanf("%d",&V);
    printf("Enter number of routes : ");
    scanf("%d",&E);
    graph = createGraph(V, E);
     for(i=0;i<E;i++)
   	 {
    	printf("\nDetails of Edge %d:-\n",i+1);
    	scanf("%d",&graph->edge[i].src);
    	scanf("%d",&graph->edge[i].dest);
    	scanf("%d",&graph->edge[i].weight);
 	}
    BellmanFord(graph, 0);
 
    return 0;
}
