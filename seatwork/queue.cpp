#include <stdio.h>
#include <stdlib.h>
#define MaxSize 5

// 循环队列的实现

typedef struct queue
{
   int front;
   int rear;
   int *base;
}SqQueue;

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
    printf("\t\t\t欢迎进入循环队列操作界面！\n");
    printf("\t 从键盘输入数字，完成对应的操作（1到7为有效操作，输入其他退出程序）\n  ");
    printf("\t 1.初始化队列\n");
    printf("\t 2.求队列的长度\n");
    printf("\t 3.入队\n");
    printf("\t 4.出队\n");
    printf("\t 5.取队列头元素\n");
    printf("\t 6.输出整个循环队列\n");
    printStart();
}

void InitQueue( SqQueue &Q )
{
    Q.base = new int[MaxSize];
    if ( !Q.base )
    {
        exit(0);
    }
    Q.front = Q.rear;
    printf("初始化成功！\n");
}

// 求循环链表的长度
int Queuelength(SqQueue Q)
{
    // int length;
    // length = (Q.rear - Q.front + MaxSize) % MaxSize;
    // printf("此时循环队列的长度为%d\n", length);
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}

// 判断队列是否为空
int isEmpty( SqQueue Q )
{
    if ( Q.rear != Q.front )
    {
        return 1;
    }
    else return 0;
}

// 入队
void EnQueue(SqQueue &Q, int e)
{
    // 判断队列是否已满
    if ( ( Q.rear + 1 ) % MaxSize == Q.front )
        printf("队列已满，写入失败！\n");
    else
    {
        printf("请输入入队的值：");
        fflush(stdin);
        scanf("%d", &e);
        Q.base[Q.rear] = e;
        Q.rear = (Q.rear + 1) % MaxSize;
        printf("入列成功！\n");
    }
    
}

// 出队
int Dequeue(SqQueue &Q, int e)
{
    //判断队列是否为空
    if ( Q.front == Q.rear )
    {
        printf("队列为空！\n");
    }
    else
    {
        e = Q.base[Q.front];
        Q.front = (Q.front + 1) % MaxSize;
        printf("出列的节点值为%d\n", e);
    }
    return 1;
}

// 输出队列的头元素
void GetHead( SqQueue &Q )
{
    if ( isEmpty( Q ) )
    {
        printf("队列的头元素为%d\n", Q.base[Q.front]);
    }
    else printf("队列为空，没有头元素！\n");
}

// 输出整个循环列
int PutQueue( SqQueue &Q , int e )
{
    SqQueue q;
    q.front = Q.front;
    if ( Q.rear != Q.front )
    {
       for (int i = 0; i < (Q.rear - Q.front + MaxSize) % MaxSize; i++)
       {
            e = Q.base[q.front];
            q.front++;
            printf("第%d个节点元素为%d\n", i+1, e);
       }
    }
    else printf("队列为空！");
    return 1;
}

// 主函数运行
int main()
{
    SqQueue Q;
    int flag = 1;
    int select, e;
    menu();
    while ( flag == 1)
    {
        printf("您选择的操作是：");
        fflush(stdin);
        scanf("%d", &select);
        switch ( select )
        {
        case 1:
            InitQueue( Q );
            break;
        case 2:
            printf("队列的长度为：%d\n", Queuelength( Q ));
            break;
        case 3:
            EnQueue ( Q , e);
            break;
        case 4:
            Dequeue( Q, e );
            break;
        case 5:
            GetHead( Q );
            break;
        case 6:
            PutQueue( Q, e );
            break;
        default:
            printf("退出程序！");
            flag = 0;
            break;
        }
    }
}













