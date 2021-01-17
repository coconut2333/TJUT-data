//
// Created by DELL on 2020/9/21.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int num;
    int sec;
}people;
typedef struct Queue{
    people data;
    struct Queue *next;
}Queue ;
typedef struct {
    Queue *front;
    Queue *rear;
} LinkQueue;
typedef LinkQueue *Node;

Node Init()
{
    Node Q=(Node)malloc(sizeof(LinkQueue));//这个申请的操作必不可少
    Queue *p=(Queue *)malloc(sizeof(Queue));
    Q->front=Q->rear=p;
    Q->front->next=NULL;
    return Q;
}
Node Enqueue(Node Q,int x)
{
    Queue *p=(Queue *)malloc(sizeof(Queue));
    p->data.sec=x;
    p->next=Q->rear->next;
    Q->rear->next=p;
    Q->rear=p;
    return Q;
}
Node Enqueue2(Node Q,int y)
{
    Queue *p=Q->rear;
    p->data.num=y;
    return Q;
}
Node Dequeue(Node Q)
{
    Queue *p=Q->front->next;
    Q->front->next=p->next;
    if(Q->rear==p){
        Q->rear=Q->front;
    }
    free(p);
    return Q;
}
int GetHead(Node Q)
{
    return Q->front->next->data.sec;
}
int GetHead2(Node Q)
{
    return Q->front->next->data.num;
}
int IsEmpty(Node Q)
{
    if(Q->front==Q->rear)   return 1;
    else return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++){
        int num,j;
        scanf("%d",&num);

        Node Q=Init();
        for(j=1;j<=num;j++){
            int temp;
            scanf("%d",&temp);
            Q=Enqueue(Q,temp);
            Q=Enqueue2(Q,j);
        }
        int init,cnt=0;
        scanf("%d",&init);
        while(!IsEmpty(Q)){
            j=1;
            while(j<init){
                cnt=(cnt+1)%num;
                if(cnt==0)  cnt=6;
                int temp=GetHead(Q);
                int temp2=GetHead2(Q);
                Q=Dequeue(Q);
                Q=Enqueue(Q,temp);
                Q=Enqueue2(Q,temp2);
                j++;
            }
            init=GetHead(Q);
            printf("%d ",GetHead2(Q));
            Q=Dequeue(Q);
        }
        printf("\n");
    }
    return 0;
}