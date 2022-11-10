#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 100

// 定义顺序栈的结构
typedef struct Stack
{
    int stacksize;
    char *base;
    char *top;
}Stack, *StackLink;

// 初始化顺序栈
void InitStack(Stack &S)
{   
    S.base = new char[MaxSize];
    if ( !S.base ) exit(0);
    S.top = S.base;
    S.stacksize = MaxSize;
    printf("初始化成功！\n");
}  

// 入栈
void PushStack(Stack &S, char &temp)
{
    char data;
    data = temp;
    *S.top = data;
    S.top ++;
    printf("成功入栈！\n");
    printf("此刻栈的值为%d\n", *(S.top-1));
}


// 出栈
Stack PopStack( Stack &S)
{
    int e;
    e = *--S.top;
    printf("出栈的元素为%d\n", e);
    return S;
}

int main()
{
    Stack S;
    Stack str;
    char res[100] = "";
    int multi; 
    // 初始化栈
    InitStack(S);
    // 测试用例
    char string[100] = "3[aa]bb";

    // printf("%d", strlen(str));
    for (int i = 0; i < strlen(string); i++)
    {
        // 保存读到字符串的数字
        if ( string[i] >= '0' && string[i] <= '9')
        {
            // 字符转换为数字
            multi = string[i] - '\0';
            printf("保存的数值为%d", multi);
        }
        // 保存读到字符串的字符
        // else if ( (string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z'))
        // {
            
        // }
        
        
    }
    
    
    
}