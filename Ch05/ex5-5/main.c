#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX_SIZE 100

typedef struct {
    int front;
    int rear;
    double* arr;
} queue_t;

void init(queue_t* q){
    q->front = q->rear = 0;

    // The queue object owns the memory block
    q->arr = (double*)malloc(QUEUE_MAX_SIZE * sizeof(double));
}

void destroy(queue_t* q){
    free(q->arr);
}

int size(queue_t* q){
    return q->rear - q->front;
}

void enqueue(queue_t* q, double item){
    q->arr[q->rear] = item;
    q->rear++;
}

double dequeue(queue_t* q){
    double item = q->arr[q->front];
    q->front++;
    return item;
}

int main(int argc, char** argv){
    // This allocates space for 2 ints and a double pointer
    // The main function owns this queue memory
    queue_t* q = (queue_t*)malloc(sizeof(queue_t));

    // This allocates space for the array which the double pointer points to
    init(q);

    enqueue(q, 6.5);
    enqueue(q, 3.5);
    enqueue(q, 6.9);

    printf("%f\n", dequeue(q));
    printf("%f\n", dequeue(q));
    printf("%f\n", dequeue(q));

    // Deallocates the array of doubles
    destroy(q);

    // Free the 2 ints and a double pointer
    free(q);
    return 0;
}