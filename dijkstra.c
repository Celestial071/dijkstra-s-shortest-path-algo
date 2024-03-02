#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

unsigned static int id_count = 0; 

typedef struct VERTEX{
    struct EDGE *edge;
    uint8_t id;
    uint8_t numEdges;
}VERTEX;



typedef struct EDGE{
    struct VERTEX *target;
    float distance;
    float time;
    //struct EDGE *next;
} EDGE;

//these heuristics are useful for A* but not for 
/*float calculate_heuristics_distance(VERTEX *current, VERTEX *next){
    return fabs(current->edge->distance - next->edge->distance);
}

float calculate_heuristics_time(VERTEX *current, VERTEX *next){
    return fabs(current->edge->time - next->edge->time);
}*/

VERTEX *start(uint8_t number_of_vertex){ //this creates the amount of vertexes I will need
    VERTEX *temp = calloc(number_of_vertex, sizeof(VERTEX));
    return temp;
}

//time to implement the creation of vertex and edges
//this gives me the control of assigning values to the vertexes
void create_vertex(VERTEX *head, uint8_t numVertices){
    for(int i = 0; i < numVertices; i++){
        head[i].id = id_count++;
        printf("Enter the total number of edges from vertex %d: ", i);
        scanf("%hhu", &head[i].numEdges);

        head[i].edge = calloc(head[i].numEdges, sizeof(EDGE));

        for(uint8_t j = 0; j < head[i].numEdges; j++){
            printf("Input the time and distance of edge %d for vertex %d: ", j, i);
            scanf("%f %f", &head[i].edge[j].time, &head[i].edge[j].distance);

            uint8_t targetIndex = 0;
            printf("Which vertex should this edge end at? (point to): ");
            scanf("%hhu", &targetIndex);

            if(targetIndex < numVertices){
                head[i].edge[j].target = &head[targetIndex];
            } else{
                printf("Invalid vertex. Please enter a value between 0 and %d.\n", numVertices);
                j--;
            }
        }
    }
}

void traverse_vertex(VERTEX *head, uint8_t vertex_number){
    for(uint8_t j = 0; j < vertex_number; j++){
        printf("The edges from Vertex %i is:-", j);
        for(uint8_t i = 0; i < head[j].numEdges; i++){
            printf("time:- %f distance:- %f\n", head[j].edge[i].time, head[j].edge[i].distance);
        }
    }
}

//need to rewrite this function
void freeMem(VERTEX *v, uint8_t vertex_number){
    //since everything is a array, first I should just free the edges and then in the end free all the vertex
    for(int i = 0; i < vertex_number; i++){
        free(v[i].edge);
    }
    free(v);
}

void dijstra_algorithm(VERTEX *vertex, uint8_t vertex_number){
    int *visited = calloc(vertex_number, sizeof(int)); //all = 0
    
}

int main(void){
    uint8_t number=0;
    puts("Enter the number of vertex you want:- \n");
    scanf("%hhu", &number);
    VERTEX*head = start(number);
    create_vertex(head, number);
    traverse_vertex(head, number); //leats just pass I instead of head
    free(head); //useless as the free logic probably is flawed.
    return 0;
}
