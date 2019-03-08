/*循环队列*/
#define MAX 20

typedef struct Queue{
    int item[MAX];
    int head,rear;
}queue;

void initQueue(queue* q){
    q->head=q->rear=0;
}

_Bool empty(queue* q){
    return q->head==q->rear;
}

_Bool full(queue* q){
    return (q->rear+1)%MAX==q->head;
}

_Bool push(queue* q,int it){
    if(!full(q)){
        q->rear=(q->rear+1)%MAX;
        q->item[q->rear]=it;
        return 1;
    }
    return 0;
}

_Bool frontPop(queue* q,int* it){
    if(!empty(q)){
        q->head=(q->head+1)%MAX;
        *it=q->item[q->head];
        return 1;
    }
    return 0;
}

int num(queue* q){
    return (q->rear-q->head)%MAX;
}
