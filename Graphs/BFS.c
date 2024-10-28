#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int* arr;
};

int isEmpty(struct queue* q){
    if(q->rear == q->front){
        return 1;
    }
    return 0;
}

int isFull(struct queue* q){
    if (q->rear == q->size-1){
        return 1;
    }
    return 0;
}

void enqueue(struct queue* q, int value){
    if(isFull(q)){
        printf("Queue is full\n");
    }
    else{
        q->rear = q->rear + 1;
        q->arr[q->rear] = value;
        // printf("Enqueued element: %d\n", value);
    }
}

int dequeue(struct queue* q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue is empty\n");
    } else{
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

int main(){
    struct queue q;
    q.size = 100;
    q.front = q.rear = 0;
    q.arr = (int*)malloc(q.size * sizeof(int));

    // BFS implementation
    int node;
    int i = 0;
    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,0,1,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i); // Enqueue i for exploration
    while (!isEmpty(&q)){
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++){
            if (a[node][j] == 1 && visited[j] == 0){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    free(q.arr);
    return 0;
}