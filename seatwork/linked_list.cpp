#include <stdio.h>
#include <stdlib.h>

typedef struct LNode                                //创建一个结构体，包含值域和指针域
{                                                   //指针结构体指针再次指向这个结构体
    int data;
    struct LNode *next;
}LNode, *LinkList;

LNode *head;                                        //头指针

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
    printf("\t\t\t欢迎进入单链表表操作界面！\n");
    printf("\t 从键盘输入数字，完成对应的操作（1到3为有效操作，输入其他退出程序）\n  ");
    printf("\t 1.创建单链表（头插法）\n");
    printf("\t 2.创建单链表（尾插法）\n");
    printf("\t 3.从中间某一个位置插入节点 \n");
    printf("\t 4.删除某一个节点 \n");
    printf("\t 5.逆置单链表\n");
    printf("\t 6.查找某一个节点的值 \n");
    printf("\t 7.打印单链表\n");
    printStart();
}

LNode *CreateHead()                                         //创建头指针
{
    head = (LNode *)malloc(sizeof(LNode));                  //开辟头节点的内存
    head -> next = NULL;                                    //头指针指向NULL
    return head;
}


LNode *CreateNext1()                                        // 头插法
{
    LNode *p, *r;
    int temp;
    printf("创建单链表（头插法）：\n");
    printf("请输入的值为1到9之间的数，输入‘0’结束\n");
    printf("请输入结点值：");
    fflush(stdin);
    scanf("%d", &temp);
    r = head;
    while ( temp != 0 )
    {
        if (( 0 < temp ) && ( temp < 10))
        {
            p = (LinkList)malloc(sizeof(LNode));
            p -> data = temp;
            p -> next = r -> next;
            r -> next = p;
        }
        printf("请输入结点值：");
        fflush(stdin);
        scanf("%d", &temp);
    }
    return head;
}


LNode *CreateNext2()                                         // 尾插法
{
    LNode *p, *r;
    int temp;
    printf("创建单链表（尾插法）：\n");
    printf("请输入的值为1到9之间的数，输入‘0’结束\n");
    printf("请输入结点值：");
    fflush(stdin);
    scanf("%d", &temp);
    r = head;
    while (temp != 0)
    {
        if (( 0 < temp ) && ( temp < 10 ))
        {
            p = (LinkList)malloc(sizeof(LNode));              // 开辟节点内存   
            p -> data = temp;                                 // 节点的值域为输入的 data  
            p -> next = NULL;                                 // 节点的指针域指向 NULL
            r -> next = p;                                    // r节点指向这个此节点（r 最开始是头结点）
            r = p;                                            // r节点是新的节点
        }
        printf("请输入结点值：");
        fflush(stdin);
        scanf("%d", &temp);
    }
    return head;
}

LNode *InsertElem()                                           // 中间插入法
{
    LNode *p, *r, *q;                                         
    int temp, add, flag;
    q = head;
    printf("你要插入节点的位置：\n");
    fflush(stdin);
    scanf("%d", &add);
    // flag = 1;
    // while (flag)
    // {
    //     int i =1; i < add; i++;
    //     q = q -> next;
    //     if (q -> next == NULL)
    //     {
    //         printf("插入失败！");
    //         flag = 0;
    //         return head;
    //     }    
    // }
    for (int i = 1; i < add; i++)
    {
        q = q -> next;
        if ( q -> next == NULL)
        {
            printf("插入失败！\n");
            return head;
        }  
    }
    printf("请输入你想要的插入的值(请输入一个1到9的整数): \n");
    fflush(stdin);
    scanf("%d", &temp);
    p = (LinkList)malloc(sizeof(LNode));
    p -> data = temp;
    p -> next = q -> next;
    q -> next = p;
    return head;
}

LNode *Delete()                                               // 删除某一个节点
{
    LNode *p, *r, *q;
    int temp, data;
    r = head;
    printf("请输入你要删除的节点的位置。\n");
    fflush(stdin);
    scanf("%d", &temp);
    for (int i = 1; i < temp; i++)                            // 遍历整个单链表
    {
        r = r -> next;                          
        if ( r -> next == NULL )                              // 判断要删除的节点是否存在
        {
            printf("没有此节点，删除失败！\n");
            return head;
        }
    }
    p = (LinkList)malloc(sizeof(LNode));                        
    p = r -> next;
    // printf("r -> next -> next = %d\n", data = r -> next -> next -> data);
    // printf("被删除节点的值域是%d\n", p -> data);
    r -> next = r -> next -> next;                             
    free(p);                                                  //释放节点
    return head;
}

LNode *Select()                                               // 查找结点
{
    LNode *p, *r;
    int temp, data;
    r = head;
    printf("请输入你想要查找的位置节点：");
    fflush(stdin);
    scanf("%d", &temp);
    for (int i = 1; i < temp; i++)                            // 遍历整个单链表
    {
        r = r -> next;                                        
        if ( r -> data == NULL)                               // 判断节点是否存在
        {
            printf("没有找到该位置的节点！\n");
            return head;
        }
    }
    p = (LinkList)malloc(sizeof(LNode));    
    p = r -> next;
    data = p -> data;
    printf("查找出来的节点的值为%d\n", data);
    return head;
}

void ReverseList(LNode *head)                                 // 逆置单链表（这里用的是类似头插法的形式）
{
    LNode *p, *q;                                             // 定义两个新的指针
    p = head -> next;                                         // 指针 p 指向头节点的下一个节点
    head -> next = NULL;                                      // 头指针的指针域指向 NULL
    while (p!=NULL)
    {
        q = p -> next;                                        // 指针 q 指向 p 的下一个节点
        p -> next = head -> next;                             // 指针 p 指向头节点的指向的 NULL
        head -> next = p;                                     // 头节点指向 p 指向的节点
        p = q;                                                // 指针 p 等于 指针 q
    }
    printf("逆置单链表\n");
}

void OutPutLink()                                             // 打印单链表
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
            head = CreateNext1();
            break;
        case 2:
            head = CreateNext2();
            break;
        case 3:
            head = InsertElem();
            break;
        case 4:
            head = Delete();
            break;
        case 5:
            ReverseList(head);
            printf("\n");
            break;
        case 6:
            head = Select();
            break;
        case 7:
            OutPutLink();
            printf("\n");
            break;
        default:
            printf("您选择退出程序， 欢迎下次光临！\n");
            flag = 0;
        }
    }
}

