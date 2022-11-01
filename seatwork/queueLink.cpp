#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef struct Node
{
    int data;
    struct Node *next;
}Node, *queueLink;

Node *head;

// 创建头结点
Node *CreateHead()
{
    head = (queueLink)malloc(sizeof(Node));
    head -> next = NULL;
    return head;
}

// 创建链队列
Node *CreateQueueLink()
{
    Node *p, *r, *rear;
    int temp, n;
    r = head;
    printf("请输入要创建链队列的长度：");
    fflush(stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("请输入第%d个节点的值", i+1 );
        fflush(stdin);
        scanf("%d", &temp);
        p = (queueLink)malloc(sizeof(Node));
        p -> data = temp;
        r -> next = p;
        p -> next = NULL;
        r = p;
    }
    printf("创建成功!\n");
    return head;
}

// 进列
Node *Push()
{
    Node *p, *r;
    int temp, n;
    r = head;
    p = (queueLink)malloc(sizeof(Node));
    printf("请输入进列的值：");
    fflush(stdin);
    scanf("%d", & temp);
    while ( r -> next != NULL )
    {
        r = r -> next;
    }
    r -> next = p;
    p -> data = temp;
    p -> next = NULL;
    return head;
}

// 出列
Node *pop()
{
    Node *p, *r;
    p = (queueLink)malloc(sizeof(Node));
    r = head;
    while ( r -> next  != NULL )
    {
        r = r -> next;
    }
    p = r;
    printf("现在出列的值是：%d\n", r -> data );
    free(p);
    return head;
}


// 打印队列
void OutQueueLink()
{
    Node *p;
    p = head;
    printf("输出链队列：\n");
    printf("head -> ");
    while ( p -> next != NULL )
    {
        p = p -> next;
        printf("%d -> ", p -> data );
    }
    printf("NULL\n");
}



int main()
{
    head = CreateHead();
    head = CreateQueueLink();
    OutQueueLink();
    head = Push();
    OutQueueLink();
    head = pop(); 
    OutQueueLink();
}




