//
// Created by DELL on 2020/9/21.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}LNode;
typedef LNode *LinkList ;

LinkList Create_Tail(int num)
{
    LinkList head,tail;
    head=(LinkList)malloc(sizeof(LNode));
    head->next=NULL;
    tail=head;

    int i;
    for(i=0;i<num;i++){
        int temp;
        scanf("%d",&temp);
        LinkList curr=(LinkList)malloc(sizeof(LNode));
        curr->data=temp;
        curr->next=tail->next;
        tail->next=curr;//第一次写的时候忘了
        tail=curr;
    }
    return head;
}
LinkList Delete(LinkList head,int min,int max)
{
    LinkList curr=head;
    while(curr->next->data<max)
    {
        if(curr->next->data<=min){
            curr=curr->next;
        }else{
            LinkList temp=curr->next;
            curr->next=temp->next;
            free(temp);
        }
    }
    return head;
}
void Print(LinkList head)
{
    LinkList temp;
    for(temp=head->next;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->data);
    }
    printf("\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++){
        int num;
        scanf("%d",&num);
        LinkList curr;
        curr=Create_Tail(num);

        int num2,j;
        scanf("%d",&num2);//操作的次数
        for(j=0;j<num2;j++){
            int temp;
            scanf("%d",&temp);
            if(temp==1){
                Print(curr);
            }else if (temp==2){
                int min,max;
                scanf("%d %d",&min,&max);
                curr=Delete(curr,min,max);
            }
        }
    }
    return 0;
}