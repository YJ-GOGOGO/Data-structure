#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

// 结点
typedef struct Node
{
    int data;
    struct Node *next;
}Node, *queueLink;

// 指针
typedef struct 
{
    Node *front;
    Node *rear;
}LinkQueue;

void printStart()                           
{
    int i;
    for ( i = 0; i < 70; i++)
    {
        printf("*");
    }
    printf("\n");   
}

void menu()
{
    printStart();
    printf("\t\t\t欢迎进入链栈操作界面！\n");
    printf("\t 从键盘输入数字，完成对应的操作（1到5为有效操作，输入其他退出程序）\n  ");
    printf("\t 1.初始化链队列\n");
    printf("\t 2.入队\n");
    printf("\t 3.出队\n");
    printf("\t 4.取队头元素\n");
    printf("\t 5.输出该队列\n");
    printStart();
}

// 链队列的初始化
LinkQueue *Initqueue()
{
    // 指针结点
    LinkQueue *q;
    // 头结点
    Node *p;
    q = (LinkQueue*)malloc(sizeof(Node));
    p = (Node*)malloc(sizeof(Node));
    p -> next = NULL;
    q -> front = p;
    q -> rear = p;
    q ->front = q->rear;
    q -> front -> next = NULL;
    printf("初始化成功\n");
    return q;
}

// 链队列的入队
void EnQueue(LinkQueue *Q, int x)
{
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    p -> data = x;
    p -> next = NULL;
    Q->rear->next = p;
    Q -> rear = p;
    printf("入队成功！\n");
}

// 出队
void Dequeue(LinkQueue *Q)
{
    Node *p;
    int x;
    p = (Node *)malloc(sizeof(Node));
    if (Q -> front == Q -> rear)
    {
        printf("对不起，队列为空！\n");
    }
    else
    {
        p = Q -> front -> next;
        x = p -> data;
        Q -> front -> next = p -> next;
        if ( Q -> rear == p )
        {
            Q -> rear = Q -> front;
        }
        printf("现在出对的元素是%d\n", x);
    }
}

// 取队头元素
void GetHeard(LinkQueue *Q)
{
    int x;
    if ( Q->rear == Q->front)
    {
        printf("对不起，空队列！\n");
    }
    else
    {
        x = Q -> front -> next -> data;
        printf("队列的头元素为%d\n", x);
    }
    
    
}

// 输出队列
void display(LinkQueue *Q)
{
    LinkQueue *k;
    k = (LinkQueue *)malloc(sizeof(Node));
    if ( Q->front == Q->rear )
    {
        printf("队列为空！\n");
    }
    else
    {
        k -> front = Q->front->next;
        while ( k->front!=NULL)
        {
            printf("%d->",k->front->data);
            k->front=k->front->next;
        }
        printf("NULL");
        printf("\n");
    }  
}


int main()
{
    int select, x, flag = 1;
    LinkQueue *p;
    menu();
    while (flag == 1)
    {
        printf("您选择的操作是：");
        fflush(stdin);
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            p = Initqueue();
            break;
        case 2:
            printf("请输入入队的元素值：");
            fflush(stdin);
            scanf("%d", &x);
            EnQueue(p, x);
            printf("\n");
            break;
        case 3:
            Dequeue(p);
            break;
        case 4:
            GetHeard(p);
            break;
        case 5:
            display(p);
            break;
        default:
            printf("您选择退出程序！\n");
            flag = 0;
            break;
        }
    }
    
}




