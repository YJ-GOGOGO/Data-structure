#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct 
{
    int array[11];
    int length;
}SeqList;

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
    printf("\t\t\t欢迎进入操作界面！\n");
    printf("\t 从键盘输入数字，完成对应的操作（1到4为有效操作，输入其他退出程序）\n  ");
    printf("\t 1.输入\n");
    printf("\t 2.排序\n");
    printf("\t 3.查找\n");
    printf("\t 4.输出\n");
    printStart();
}

void Input(SeqList *q){
    int i;
    for ( i = 1; i < q->length; i++)
    {
        scanf("%d", &q->array[i]);
    }
    
}

int BinarySearch(SeqList *q, int x)
{
    int low = 1, high = q -> length,mid;
    while (low <= high)
    {
        mid = (low+high)/2;
        if ( q -> array[mid] == x )
        {
            return mid;
        }
        if ( q -> array[mid] > x )
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return 0;
}

void BubbleSort(SeqList *q)
{
    int i, j, exchange;
    for ( i = 1; i < q -> length-1; i++)
    {
        for ( j = 9; j >= i; j--)
        {
            if ( q -> array[j+1] < q -> array[j])
            {
                q -> array[0] = q -> array[j+1];
                q -> array[j+1] = q -> array[j];
                q -> array[j] = q -> array[0];   
                exchange = 1; 
            } 
        }
        if(!exchange)
            break;
    }
}

void Output(SeqList *q)
{
    int i;
    for ( i = 1; i <= 10; i++)
    {
        printf("%3d", q -> array[i]);
    }
    
}

int main()
{
    int x, p, select, flag = 1;
    SeqList *q;
    q = (SeqList *)malloc(sizeof(SeqList));
    q -> length = 11;
    menu();
    while (flag == 1)
    {
        printf("您选择的操作是:");
        fflush(stdin);
        scanf("%d", &select);
        switch ( select )
        {
        case 1:
            printf("\t请输入10个整数：");
            Input(q);
            printf("\t输入成功!\n\n");
            break;
        case 2:
            BubbleSort(q);
            printf("\t排序成功！\n\n");
            break;
        case 3:
            printf("\t请输入任意一个整数，查找是否在改数组内：");
            fflush(stdin);
            scanf("%d", &x);
            p = BinarySearch(q, x);
            if (p != 0)
                printf("\t数组array的第%d个元素是%d\n\n", p, x);
            else
                printf("\t对不起，您输入的数据%d不在数组array中\n\n", x);
            break;
        case 4:
            printf("\t输出元素:");
            Output( q );
            printf("\n\n");
            break;
        default:
            printf("终止结束！");
            flag = 0;
            break;
        }
    }       
}














