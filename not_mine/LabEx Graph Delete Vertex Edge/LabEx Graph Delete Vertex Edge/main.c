#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct Graph {
  int numVertices;
  Node **adjList;
} Graph;

void createGraph(Graph *graph, int numVertices) {
  graph->numVertices = numVertices;
  graph->adjList = (Node **)malloc(numVertices * sizeof(Node *));

  for (int i = 0; i < numVertices; i++) {
    graph->adjList[i] = NULL;
  }
}

void addEdge(Graph *graph, int src, int dest) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = dest;
  newNode->next = graph->adjList[src];
  graph->adjList[src] = newNode;

  // Undirected graph: add edge in both directions
  newNode = (Node *)malloc(sizeof(Node));
  newNode->data = src;
  newNode->next = graph->adjList[dest];
  graph->adjList[dest] = newNode;
}

void deleteEdge(Graph *graph, int src, int dest) {
    Node *temp, *prev;
    // Find the edge to be deleted in the adjacency list of src
    temp = graph->adjList[src];
    prev = NULL;
    while (temp != NULL && temp->data != dest) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        // Edge found
        if (prev == NULL) {
            // Edge is the first in the list
            graph->adjList[src] = temp->next;
        } else {
            // Edge is in the middle or at the end of the list
            prev->next = temp->next;
        }
        free(temp);
        // Undirected graph: remove edge from dest's adjacency list
        temp = graph->adjList[dest];
        prev = NULL;
        while (temp != NULL && temp->data != src) {
            prev = temp;
            temp = temp->next;
        }

        if (temp != NULL) {
            // Edge found
            if (prev == NULL) {
                // Edge is the first in the list
                graph->adjList[dest] = temp->next;
            } else {
                // Edge is in the middle or at the end of the list
                prev->next = temp->next;
            }
            free(temp);
        }
    }
}

void deleteNode(Graph *graph, int node) {
  // Remove edges from other nodes pointing to the node to be deleted
  for (int i = 0; i < graph->numVertices; i++) {
    deleteEdge(graph, i, node);
  }

  // Remove the node itself from the graph's data structure
  free(graph->adjList[node]);
  graph->adjList[node] = NULL;
}

void printGraph(Graph *graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    printf("Node %d: ", i);
    Node *temp = graph->adjList[i];
    while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  Graph graph;

  // Create a graph with 5 vertices
  createGraph(&graph, 5);
    printf("Create Struct Graph\n");
  // Add edges
  addEdge(&graph, 0, 1);
  addEdge(&graph, 0, 2);
  addEdge(&graph, 1, 3);
  addEdge(&graph, 2, 3);
  addEdge(&graph, 3, 4);

    
  // Print the graph
  printGraph(&graph);
  // Delete edge (0, 2)
  deleteEdge(&graph, 0, 2);
    printf("Delete Graph edge 0,2 \n");
  // Print the graph after deleting the edge
  printGraph(&graph);
    printf("Delete Graph vertex 3 \n");
  // Delete node 3
  deleteNode(&graph, 3);

  // Print the graph after deleting the node
  printGraph(&graph);

  return 0;
}
