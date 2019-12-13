#include <stdio.h>
#include <stdlib.h>

//A structure to represent nodes
typedef struct Node{
	int m_dest;
	struct Node* m_next;
}Node;

//A structure to represent an adjacent list.
typedef struct AdjList{
	struct Node* m_head;
}AdjList;

//A structure to represent graph
typedef struct  Graph
{
	int m_V;
	struct AdjList* m_array;
}Graph;



//TODO: function to creating newNode
Node* createNode(int dest);

//TODO: function to create a new graph
Graph* createGraph(int v);

//TODO: function to add new edge
void addEdge(Graph *graph, int src, int dest); 

//TODO: function to print graph
void printGraph(Graph *graph);



int main(){
	Graph *graph = createGraph(3);
	addEdge(graph, 0, 1);
	addEdge(graph, 1, 2);
	printGraph(graph);
}



Node* createNode(int dest){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->m_dest = dest;
	newNode->m_next = NULL;
	return newNode;
}


Graph* createGraph(int V){
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	graph->m_V = V;

	graph->m_array = (AdjList*)malloc(sizeof(AdjList)*V);
	for(int v = 0; v < V; v++){
		graph->m_array[v].m_head = NULL;
	}
	return graph;
}

void addEdge(Graph *graph, int src, int dest){
	Node* newNode = createNode(dest);
	newNode->m_next = graph->m_array[src].m_head;
	graph->m_array[src].m_head = newNode;

	//It'll be an undirected graph
	//Therefore, we do the same thing for src
	newNode = createNode(src);
	newNode->m_next = graph->m_array[dest].m_head;
	graph->m_array[dest].m_head = newNode;
}


void printGraph(Graph *graph){
	for(int v = 0; v < graph->m_V; ++v){
		printf("adjacency list of vertex %d\n", v);
		Node* keep = graph->m_array[v].m_head;
		printf("head");
		while(keep){
			printf("-> %d", keep->m_dest);
			keep = keep->m_next;
		}
		printf("\n");
	}
}