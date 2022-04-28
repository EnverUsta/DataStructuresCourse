#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	int m_dest;
	struct Node* m_next;
}Node;


typedef struct AdjList
{
	struct Node* m_head;
}AdjList;


typedef	struct Graph
{
	int m_V;
	struct AdjList* m_array;	
}Graph;


Graph* createGraph(int V);

Node* createNode(int dest);

void addEdge(Graph *graph, int src, int dest);

void printGraph(Graph *graph);


int main(){
	Graph *graph = createGraph(5);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 0, 3);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 1);
	addEdge(graph, 2, 2);
	addEdge(graph, 3, 3);
	addEdge(graph, 4, 4);

	printGraph(graph);
}



Graph* createGraph(int V)
{
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	graph->m_V = V;
	graph->m_array = (AdjList*)malloc(sizeof(AdjList)*V);
	for(int v = 0; v < V; v++){
		graph->m_array[v].m_head = NULL;
	}
	return graph;
}

Node* createNode(int dest)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->m_dest = dest;
	node->m_next = NULL;
	return node;
}

void addEdge(Graph *graph, int src, int dest)
{
	Node* newNode = createNode(dest);
	newNode->m_next = graph->m_array[src].m_head;
	graph->m_array[src].m_head = newNode;

	// because of the undirected graph following codes are significant.
	newNode = createNode(src);
	newNode->m_next = graph->m_array[dest].m_head;
	graph->m_array[dest].m_head = newNode;
}


void printGraph(Graph *graph)
{
	for(int i = 0; i < graph->m_V; ++i){
		Node* iter = graph->m_array[i].m_head;
		printf("vertex: %d\n", i);
		printf("head");
		while(iter)
		{
			printf("-> %d", iter->m_dest);
			iter = iter->m_next;
		}
		printf("\n");
	}
}