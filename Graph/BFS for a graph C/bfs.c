#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct AdjListNode{
	int m_dest;
	struct AdjListNode *m_next;
}AdjListNode;

typedef struct AdjList{
	struct AdjListNode *m_head;
}AdjList;

typedef struct Graph{
	int m_V;
	struct AdjList *m_array;
}Graph;


Graph* createGraph(int V);
AdjListNode* createNode(int dest);
void addEdge(Graph *graph, int src, int dest);
void printGraph(Graph *graph);

void bfs(Graph *graph, int startPoint);


int main(){
	Graph *graph = createGraph(6);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 4);
	addEdge(graph, 2, 5);
	addEdge(graph, 3, 5);
	addEdge(graph, 4, 6);
	addEdge(graph, 5, 6);

	bfs(graph, 1);

}

void bfs(Graph *graph, int startPoint)
{
	int *isVisited = (int*)malloc(sizeof(int)*graph->m_V);
	for(int i = 0; i < graph->m_V; ++i)
		isVisited[i] = 0;

	Node* queue = createQueue();

	isVisited[startPoint] = 1;
	enqueue(&queue, startPoint);

	while(!isEmpty(queue))
	{
		startPoint = dequeue(&queue);
		printf("%d\n", startPoint);

		AdjListNode *iter = graph->m_array[startPoint].m_head;
		while(iter)
		{
			if(!isVisited[iter->m_dest])
			{
				isVisited[iter->m_dest] = 1;
				enqueue(&queue, iter->m_dest);
			}
			iter = iter->m_next;
		}		
	}
}


Graph* createGraph(int V)
{
	Graph* graph = malloc(sizeof(Graph));
	graph->m_V = V;
	graph->m_array = malloc(sizeof(AdjList));

	for(int i = 0; i < V; ++i)
	{
		graph->m_array[i].m_head = NULL;
	}
	return graph;
}

AdjListNode* createNode(int dest)
{
	AdjListNode *newNode = malloc(sizeof(AdjListNode));
	newNode->m_dest = dest;
	newNode->m_next = NULL; 
	return newNode;
}


void addEdge(Graph *graph, int src, int dest)
{
	AdjListNode *newNode = createNode(dest);
	newNode->m_next = graph->m_array[src].m_head;
	graph->m_array[src].m_head = newNode;

	//Undirected graph
	newNode = createNode(src);
	newNode->m_next = graph->m_array[dest].m_head;
	graph->m_array[dest].m_head = newNode;
}

void printGraph(Graph *graph)
{
	for(int i = 0; i < graph->m_V; ++i){
		AdjListNode* iter = graph->m_array[i].m_head;
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