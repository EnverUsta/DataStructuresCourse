#include <stdio.h>
#include <stdlib.h>


//A structure to represent adjacency list node.
typedef struct AdjListNode{
	int m_dest;
	struct  AdjListNode *m_next;
}AdjListNode;

//A structure to represent an adjacency list.
typedef struct AdjList{
	struct AdjListNode *m_head;
}AdjList;

//A structure to represent a graph,
//A graph is an array of adjacency list.
//Size of array will be m_V(number of vertices in graph).
typedef struct Graph
{
	int m_V;
	struct AdjList *m_array; 
}Graph;


//A utility function to create new adjacent list node
AdjListNode* newAdjListNode(int dest){
	AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
	newNode->m_dest = dest;
	newNode->m_next = NULL;
	return newNode;
}


Graph* createGraph(int V){
	//Creating a graph
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	graph->m_V = V;

	graph->m_array = (AdjList*)malloc(sizeof(AdjList)*V);

	//Assigning to null each AdjList->m_head
	for(int i = 0; i < V; ++i){
		graph->m_array[i].m_head = NULL;
	}
	return graph;
}



//Adds an edge to an undirected graph
void addEdge(Graph *graph, int src, int dest){
	AdjListNode *newNode = newAdjListNode(dest);

	newNode->m_next = graph->m_array[src].m_head;
	graph->m_array[src].m_head = newNode;


	newNode = newAdjListNode(src);
	newNode->m_next = graph->m_array[dest].m_head;
	graph->m_array[dest].m_head = newNode;
}


//A utility function to print the adjacency list
//representation of graph
void printGraph(Graph *graph){

	int v;
	for(v = 0; v < graph->m_V; v++){
		AdjListNode *pCrawl = graph->m_array[v].m_head;
		printf("adjacency list of vertex %d\n head", v);
		while(pCrawl){
			printf("-> %d", pCrawl->m_dest);
			pCrawl = pCrawl->m_next;
		}
		printf("\n");
	}
}


int main(){
	Graph *graph = createGraph(5);	//Creating a graph with 5 vertices(nodes).
	addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4); 
  
    // print the adjacency list representation of the above graph 
    printGraph(graph); 
}