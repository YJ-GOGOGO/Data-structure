#include <stdio.h>
#include <stdlib.h>

//定义双链表的结构
typedef struct DuLNode 
{
    int data;
    struct DuLNode *prior;
    struct DuLNode *next;  
}DuLNode, *DuLNodeList;

DuLNode *head;

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
    printf("\t 1.创建双链表(头插法)\n");
    printf("\t 2.创建双链表(尾插法)\n");
    printf("\t 3.插入节点\n");
    printf("\t 4.删除节点\n");
    printf("\t 5.打印反转双链表\n");
    printf("\t 6.打印双链表\n");
    printStart();
}

// 创建表头
// 创建 prior指针 和 next 指针
DuLNode *CreateHead()                                         
{
    head = (DuLNodeList)malloc(sizeof(DuLNode));                  
    head -> next = NULL;                                  
    head -> prior = NULL;                                       
    return head;
}

// 创建双链表（头插法）
DuLNode *CreateDuL()
{
    DuLNode *p, *r;
    int length;
    int temp;
    r = head;
    printf("请输入你创建双链表的长度：");
    fflush(stdin);
    scanf("%d", &length);
    for (int  i = 0; i < length; i++)
    {
        printf("请输入第%d个节点的值为：", i+1);
        p = (DuLNodeList)malloc(sizeof(DuLNode));
        scanf("%d", &temp);
        fflush(stdin);
        p -> data = temp;
        p -> prior = r;
        p -> next = r -> next;
        r -> next = p;
    }
    return head; 
}

// 创建双链表（尾插法）
DuLNode *CreateDuL2()                                            
{
    DuLNode *p, *r;
    int length, temp;
    r = head;
    printf("请输入你创建双链表的长度：");
    fflush(stdin);
    scanf("%d", &length);
    for (int i = 0; i < length; i++)
    {
        printf("请输入第%d个节点的值为：", i+1);
        p = (DuLNodeList)malloc(sizeof(DuLNode));
        fflush(stdin);
        scanf("%d", &temp);
        p -> data = temp;
        p -> next = NULL;
        p -> prior = r;
        r -> next = p;
        r = p;
    }
    return head;   
}

// 从中间插入节点
DuLNode *Insert()
{
    DuLNode *p, *r;
    int temp, location, i = 0;
    r = head;
    // for ( i = 1; r -> next != NULL; i++)
    //     r = r -> next;
    while ( r -> next != NULL  )
    {
        r = r -> next;
        i++;
    }
    printf("现在data=%d\n", r->data);
    printf("总共有%d个节点\n", i);
    printf("请输入你想要插入节点的位置：");
    fflush(stdin);
    scanf("%d", &location);
    printf("请输入插入节点的值：");
    fflush(stdin);
    scanf("%d", &temp);
    if ( i >= location )
    {
        p = (DuLNodeList)malloc(sizeof(DuLNode));
        p -> data = temp;
        p -> prior = r;
        r -> prior -> next = p;
        p -> next = r;
        r -> prior = p;
        return head;
    }
    else if ( i < location )
    {
        printf("插入失败!\n");
    }
    return head;   
}

// 删除某一个节点
DuLNode *Delete()
{
    DuLNode *r, *p;
    int temp, i = 0;
    r = head;
    printf("请输入你想要删除哪一个位置上的节点：");
    fflush(stdin);
    scanf("%d", &temp);
    // 确定要删除的节点的前一个位置
    // while ( r -> next && i < temp-1 )
    // {
    //     i++;
    //     r = r -> next;
    // }

    // 判断要删除的节点是否存在
    for (int i = 0; r -> next; i++)
    {   
        r = r -> next;
        if ( i < temp -1 )
        {
            printf("删除失败！\n");
            return head;
        }       
    }
    p = r -> next;
    p -> data = r -> next -> data;
    p -> prior -> next = p -> next;
    p -> next -> prior = p -> prior;
    free(p);
    return head;
}

// 打印双链表
void OutPutList()
{
    DuLNode *p;
    p = head;
    printf("打印双链表\n");
    while (p -> next != NULL)
    {
        p = p -> next;
        printf("%d ->", p -> data);
    }
    printf("NULL");
    printf("\n");  
}

// 反转双链表（类似头插法）
void OutPutListReverse()
{
    DuLNode *p, *r;
    p = head -> next;
    head -> next = NULL;
    while ( p != NULL)
    {
        r = p -> next;
        p -> next = head -> next;
        head -> next = p;
        p = r;
    }
    printf("逆置双链表\n");
    
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
            head = CreateDuL();
            break;
        case 2:
            head = CreateDuL2();
            break;
        case 3:
            head = Insert();
            break;
        case 4:
            head = Delete();
            break;
        case 5:
            OutPutListReverse();
            break;
        case 6:
            OutPutList();
            break;
        default:
            printf("终止结束！");
            flag = 0;
            break;
        }
    }       
}