#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10

// 定义顺序栈的结构
typedef struct Stack
{
    int stacksize;
    int *base;
    int *top;
}Stack, *StackLink;



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
    printf("\t\t\t欢迎进入顺序栈操作界面！\n");
    printf("\t 从键盘输入数字，完成对应的操作（1到7为有效操作，输入其他退出程序）\n  ");
    printf("\t 1.初始化栈\n");
    printf("\t 2.判断栈是否为空\n");
    printf("\t 3.入栈\n");
    printf("\t 4.出栈\n");
    printf("\t 5.取栈顶元素\n");
    printf("\t 6.输出整个顺序栈\n");
    printStart();
}


// 初始化顺序栈
void InitStack(Stack &S)
{   
    S.base = new int[MaxSize];
    if ( !S.base ) exit(0);
    S.top = S.base;
    S.stacksize = MaxSize;
    printf("初始化成功！\n");
}   

// 判断顺序栈的情况
int isEmpty( Stack S )
{
    if ( *S.base == *S.top )
        return 1;
    return 0;
}

// 入栈
void PushStack(Stack &S)
{
    int data;
    printf("请输入进栈的整数值：");
    fflush(stdin);
    scanf("%d", &data);
    if ( (S.top - S.base ) == S.stacksize )
    {
        printf("栈已经满了！");
    }  
    else{
        *S.top = data;
        S.top ++;
        printf("成功入栈！\n");
        printf("此刻栈的值为%d\n", *(S.top-1));
    }
}

// 出栈
Stack PopStack( Stack &S)
{
    int e;
    if ( S.base == S.top )
    {
        printf("栈已经空了！\n");
    }
    else{
        e = *--S.top;
        printf("出栈的元素为%d\n", e);
    }
    return S;
}

// 取出栈顶元素
void GetTop( Stack &S )
{
    if ( isEmpty( S ) )
    {
        printf("栈为空，没有元素！\n");
    }
    else printf("此时栈顶的元素为：%d\n", *(S.top-1));
}

// 顺序栈的大小
int Stacklen( Stack S )
{
    return S.top - S.base;
}

// 输出该顺序栈
void PutStack( Stack S)
{
    int length = Stacklen( S );
    if ( S.base != S.top )
    {
        for (int i = 0; i < length; i++)
        {
            printf("第%d个元素是%d\n", i+1, S.base[i]);
        }
    }
    else printf("栈已经没有元素了！\n");
}


int main()
{
    Stack S;
    int flag = 1;
    int select, e;
    menu();
    while (flag == 1)
    {
        printf("您选择的操作是:");
        fflush(stdin);
        scanf("%d", &select);
        switch ( select )
        {
            case 1:
                InitStack( S );
                break;
            case 2:
                if ( isEmpty(S) ) 
                {
                    printf("栈为空！\n");
                }
                else {
                    printf("栈不为空！\n");
                }
                break;
            case 3:
                PushStack( S );
                break;
            case 4:
                PopStack( S );
                break;
            case 5:
                GetTop( S );
                break;
            case 6:
                PutStack( S );
                break;
            default:
                printf("退出程序！");
                flag = 0;
                break;
        }
    }    
}