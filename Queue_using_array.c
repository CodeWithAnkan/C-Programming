#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int* arr;
};

int isFull(struct queue* q){
    if(q->rear == q->size - 1){
        // printf("Queue is full\n");
        return 1;
    }
    return 0;
}

int isEmpty(struct queue* q){
    if(q->rear == -1 || q->front == q->rear){
        // printf("Queue is empty\n");
        return 1;
    }
    return 0;
}

int enqueue(struct queue* q, int value){
    if (isFull(q)){
        printf("Queue is full\n");
    } else {
        q->rear = q->rear + 1;
        q->arr[q->rear] = value;
    }
    
}

int dequeue(struct queue* q){
    int a = -1;
    if (isEmpty(q)){
        printf("Queue is empty\n");
    } else {
        q->front++;
        a = q->arr[q->front];
    }
    return a;    
}

int main(){
    struct queue q;
    q.size = 4;
    q.front = q.rear = -1;
    q.arr = (int*)malloc(q.size * sizeof(int));

    //Enqueue few elements

    printf("Enqueuing Elements %d\n", enqueue(&q, 12));
    printf("Enqueuing Elements %d\n", enqueue(&q, 29));
    printf("Enqueuing Elements %d\n", enqueue(&q, 45));
    printf("Enqueuing Elements %d\n", enqueue(&q, 34));
    printf("\n");
    printf("Dequeuing Elements %d\n", dequeue(&q));
    printf("Dequeuing Elements %d\n", dequeue(&q));
    printf("Dequeuing Elements %d\n", dequeue(&q));
    printf("Dequeuing Elements %d\n", dequeue(&q));

    printf("Enqueuing Elements %d\n", enqueue(&q, 18));


    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if (isFull(&q)){
        printf("Queue is full\n");
    }
    return 0;
}