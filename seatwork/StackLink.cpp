#include <stdio.h>
#include <stdlib.h>

// 这是链栈的实例代码

typedef struct Stack
{
    int data;
    struct Stack *next;
}Stack, *StackLink;

// 头结点
Stack *head;

// 创建头结点
Stack *CreateHead()
{
    head = (StackLink)malloc(sizeof(Stack));
    head -> next = NULL;
    return head;
}

// 创建栈链（这里用单链表的头插法）
Stack *CreateNext()
{
    Stack *p, *r;
    int temp, n = 0;
    r = head;
    printf("请输入你要创建栈的长度：");
    fflush(stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("请输入第%d栈的值：", i+1 );
        fflush(stdin);
        scanf("%d", &temp);
        p = (StackLink)malloc(sizeof(Stack));
        p -> data = temp;
        p -> next = r -> next;
        r -> next = p;
    }
    printf("创建完成！\n");
    return head;
}

// 进栈
Stack *PushStack()
{
    Stack *p, *r;
    int temp, n;
    r = head;
    p = (StackLink)malloc(sizeof(Stack));
    printf("请输入要进栈的值：");
    fflush(stdin);
    scanf("%d", &temp);
    p -> data = temp;
    p -> next = r -> next;
    r -> next = p;
    printf("进栈成功！\n");
    return head;
}

// 取栈顶的值
void GetStackfirst()
{
    // 判断是否有栈顶的值
    if ( head -> next != NULL )
    {
        printf("此时栈顶的值为:%d", head -> next -> data );
    }
    else printf("栈顶此刻没有值！");
}

// 打印栈链的值
void OutStackLink()
{
    Stack *p;
    p = head;
    printf("打印栈链：\n");
    printf("head -> ");
    while ( p -> next != NULL )
    {
        p = p -> next;
        printf("%d ->", p -> data);
    }
    printf("NULL");
    printf("\n");
}

int main()
{
    head = CreateHead();
    CreateNext();
    head = PushStack();
    OutStackLink();
    GetStackfirst();
}
