#include<stdio.h>
#include<stdlib.h>

struct cirular_queue{
    int size;
    int front;
    int rear;
    int* arr;
};

int isFull(struct cirular_queue* q){
    if((q->rear + 1)% q->size == q->front){
        // printf("Overflow\n");
        return 1;
    }
    return 0;
}

int isEmpty(struct cirular_queue* q){
    if(q->rear == -1 || q->front == q->rear){
        // printf("Underflow\n");
        return 1;
    }
    return 0;
}

int enqueue(struct cirular_queue* q, int value){
    if (isFull(q)){
        printf("Overflow\n");
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = value;
        printf("Enqueuing Element: %d\n", value);
    }
    
}

int dequeue(struct cirular_queue* q){
    int a = -1;
    if (isEmpty(q)){
        printf("Underflow\n");
    } else {
        q->front = (q->front + 1) % q->size;
        a = q->arr[q->front];
    }
    return a;    
}

int main(){
    struct cirular_queue q;
    q.size = 4;
    q.front = q.rear = 0;
    q.arr = (int*)malloc(q.size * sizeof(int));

    //Enqueue few elements

    enqueue(&q, 12);
    enqueue(&q, 29);
    enqueue(&q, 45);
    printf("\n");
    printf("Dequeuing Elements %d\n", dequeue(&q));
    printf("Dequeuing Elements %d\n", dequeue(&q));
    printf("Dequeuing Elements %d\n", dequeue(&q));
    printf("\n");
    enqueue(&q, 18);


    if(isEmpty(&q)){
        printf("Undeflow");
    }
     if (isFull(&q)){
        printf("Overflow\n");
    }
    return 0;
}