#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode, *LinkList;

LNode *head;

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
    printf("\t\t\t欢迎进入顺序表操作界面！\n");
    printf("\t 从键盘输入数字，完成对应的操作（1到3为有效操作，输入其他退出程序）\n  ");
    printf("\t 1.创建单链表\n");
    printf("\t 2.逆置单链表\n");
    printf("\t 3.打印单链表\n");
    printStart();
}

LNode *CreateHead()
{
    head = (LNode *)malloc(sizeof(LNode));
    head -> next = NULL;
    return head;
}

LNode *CreateNext()
{
    LNode *p, *r;
    int temp;
    printf("创建单链表：\n");
    printf("请输入的值为1到9之间的数，输入‘0’结束\n");
    printf("请输入结点值：");
    fflush(stdin);
    scanf("%d", &temp);
    r = head;
    while (temp != 0)
    {
        if (( 0 < temp ) && ( temp < 10 ))
        {
            p = (LinkList)malloc(sizeof(LNode));
            p -> data = temp;
            p -> next = NULL;
            r -> next = p;
            r = p;
        }
        printf("请输入结点值：");
        fflush(stdin);
        scanf("%d", &temp);
    }
    return head;
}

void ReverseList(LNode *head)
{
    LNode *p, *q;
    p = head -> next;
    head -> next = NULL;
    while (p!=NULL)
    {
        q = p -> next;
        p -> next = head -> next;
        head -> next = p;
        p = q;
    }
    printf("逆置单链表\n");
}

void OutPutLink()
{
    LNode *p;
    p = head;
    printf("打印单链表：\n");
    while (p -> next != NULL)
    {
        p = p -> next;
        printf("%d ->", p -> data);
    }
    printf("NULL");
    printf("\n");
}

int main()
{
    int select, n, flag = 1;
    head = CreateHead();
    menu();
    while (flag == 1)
    {
        printf("您选择的操作是:");
        fflush(stdin);
        scanf("%d", &select);
        switch ( select )
        {
        case 1:
            head = CreateNext();
            break;
        case 2:
            ReverseList(head);
            printf("\n");
            break;
        case 3:
            OutPutLink();
            printf("\n");
            break;
        default:
            printf("您选择退出程序， 欢迎下次光临！\n");
            flag = 0;
        }
    }
    
}

