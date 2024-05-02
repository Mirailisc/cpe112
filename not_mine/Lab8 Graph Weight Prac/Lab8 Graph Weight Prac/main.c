#include <stdio.h>
#include <stdlib.h>

typedef struct adjVertex{
    int weight;
    int key;
    void* vertex;
    struct adjVertex* next;
}adjVertex;

typedef struct Vertex{
    int key;
    struct Vertex* next;
    struct adjVertex* adjListHead;
}Vertex;

void freeGraph(Vertex* vertexListHead) {
    Vertex *ptr = vertexListHead;
    while (ptr!=NULL){
        adjVertex *adj = ptr->adjListHead;
        while (adj!=NULL){
            adjVertex *temp = adj->next;
            free(adj);
            adj = temp;
        }
        Vertex* temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
}

Vertex* addVertex(int key,Vertex** vertexListHead){
    Vertex *newVertex = (Vertex*) malloc(sizeof(Vertex));
    newVertex->key = key;
    newVertex->next = NULL;
    newVertex->adjListHead = NULL;
    if (*vertexListHead==NULL) *vertexListHead = newVertex;
    else{
        Vertex *ptr = *vertexListHead;
        while (ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next = newVertex;
    }
    return newVertex;
}

void addEdge(int start,int end,int weight, Vertex** vertexListHead){
    Vertex *ptrStart = *vertexListHead;
    Vertex *ptrEnd = *vertexListHead;
    while (ptrStart!=NULL && ptrStart->key != start) ptrStart = ptrStart->next;
    while (ptrEnd!=NULL && ptrEnd->key != end) ptrEnd = ptrEnd->next;
    
    if (ptrStart==NULL) ptrStart = addVertex(start, vertexListHead);
    if (ptrEnd==NULL) ptrEnd = addVertex(end, vertexListHead);
    
    adjVertex* newEdge = malloc(sizeof(adjVertex));
    newEdge->weight = weight;
    newEdge->key = end; //End
    newEdge->vertex = ptrEnd; //End
    newEdge->next = NULL;
    if (ptrStart->adjListHead == NULL) ptrStart->adjListHead = newEdge;
    else{
        adjVertex* adj = ptrStart->adjListHead;
        while (adj->next != NULL) adj = adj->next;
        adj->next = newEdge;
    }
}

void printGraph(Vertex* vertexListHead){
    Vertex* ptr = vertexListHead;
    while (ptr!=NULL){
        adjVertex* adj = ptr->adjListHead;
        while (adj!=NULL){
            printf("%d -> %d (%d)\n",ptr->key,adj->key,adj->weight);
            adj = adj->next;
        }
        ptr = ptr->next;
    }
}


int main(void) {
    Vertex* vertexListHead = NULL;
    
    int n,a,b,w;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d %d %d",&a,&b,&w);
        addEdge(a, b, w, &vertexListHead);
    }
    
    printGraph(vertexListHead);
    freeGraph(vertexListHead);
    return 0;
}
