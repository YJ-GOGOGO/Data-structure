#include <stdio.h>
#define MAXSIZE 100

typedef struct                           //定义顺序表的最大长度                                       
{
    int array[MAXSIZE];
    int length;
}SequenceList;

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
    printf("\t 从键盘输入数字，完成对应的操作（1到8为有效操作，输入其他退出程序）\n  ");
    printf("\t 1.从键盘连续输入n个整数，建立一个顺序表\n");
    printf("\t 2.输出改顺序表的\n");
    printf("\t 3.从键盘输入一个整数，插入到顺序表的头部\n");
    printf("\t 4.从键盘输入一个整数，插入到顺序表的尾部\n");
    printf("\t 5.从键盘输入一个整数，插入到顺序表的指定位置\n");
    printf("\t 6.从顺序表的头部删除一个节点\n");
    printf("\t 7.从顺序表的尾部删除一个节点\n");
    printf("\t 8.从顺序表的指定位置删除一个节点\n");
    printStart();
}

/*
创建顺序表
*/
void inputSL(SequenceList *P_SL)                              
{
    int i, length;
    printf("请输入将要建立的顺序表的节点个数（长度）：");
    scanf("%d", &length);
    printf("请输入%d个数据（用空格分隔，回车结束输入）：", length);
    for ( i = 0; i < length; i++)
    {
        scanf("%d", &P_SL->array[i]);
    }
    P_SL -> length = length;
}

/*
输出顺序表
*/
void outputSL(SequenceList *P_SL, int length)
{
    int i;
    printf("输入顺序表：\n");
    if (length == 0)
    {
        printf("对不起，顺序表为空，无法输出，请先选择输入。\n");
    }
    else
        for ( i = 0; i < length; i++)
        {
            printf("array[%d] = %d\n", i, P_SL->array[i]);
        }
        
}

void insertSLHead(SequenceList *P_SL)
{
    int i, data = 0;
    printf("请输入一个整数，从头部插入顺序表中:");
    fflush(stdin);
    scanf("%d", &data);
    if (P_SL->length == 0)
    {               
        P_SL->length++;
        P_SL->array[0] = data;
    }
    else
    {
        P_SL->length++;
        for ( i = P_SL->length-2; i >= 0; i--)
            P_SL->array[i+1] = P_SL->array[i];
        P_SL->array[0] = data;
    }
}

void insertSLTail(SequenceList *P_SL)      //从尾部插入操作
{
    int data = 0;
    printf("请输入一个整数，从尾部插入顺序表中：");
    fflush(stdin);
    scanf("%d", &data);
    P_SL -> length++;
    P_SL -> array[P_SL->length-1] = data;
}

void instertSLLocation(SequenceList *P_SL)     //指定位置插入一个结点
{
    int data, location, i;
    fflush(stdin);
    printf("请输入查到顺序表中的位置（下标值）：");
    scanf("%d", &location);
    if (location == 0)
    {
        insertSLHead(P_SL);
    }
    else if (location == P_SL ->length)
    {
        insertSLTail(P_SL);
    }
    else if (location > P_SL -> length)
    {
        printf("输入错误，插入位置不自在顺序表中\n");
    }
    else
    {
        P_SL -> length++;
        printf("请输入要插入的节点值（一个整数）:");
        scanf("%d", &data);
        for ( i = P_SL -> length-2; i >= location-1; i--)
        {
            P_SL ->array[i+1] = P_SL -> array[i];
        }
        P_SL -> array[location] = data;
    }
    
    
}

void deleteSLHead(SequenceList *P_SL)
{
    int i;
    printf("从头部删除一个节点：\n");
    if (P_SL -> length == 0)
    {
        printf("顺序表不能为空，无法执行删除操作！\n");
    }
    else{
        for ( i = 0; i < P_SL -> length; i++)
        {
            P_SL -> array[i] = P_SL -> array[i];
        }
        P_SL -> length--;
    }
}

void deleteSLTail(SequenceList *P_SL)
{
    printf("从尾部删除一个结点：\n");
    if (P_SL -> length==0)
    {
        printf("顺序表为空，无法执行删除操作！\n");
    }
    else
        P_SL -> length--;

}

void deleteSLLocation(SequenceList *P_SL)
{
    int location, data, i;
    fflush(stdin);
    printf("请输入删除结点的位置（下标值）：");
    scanf("%d", &location);
    if (location == 0)
    {
        deleteSLHead(P_SL);

    }
    else if (location > P_SL -> length)
    {
        printf("输入错误， 删除位置不在顺序表中\n");
    }
    else
    {
        for ( i = location; i<=P_SL->length-1; i++)
        {
            P_SL -> array[i] = P_SL -> array[i+1];
        }
        P_SL -> length--;
    }
}

int main()
{
    SequenceList SL, *P_SL;
    int flag = 1;
    char selectCode;
    P_SL = &SL;
    SL.length = 0;
    menu();
    while (flag == 1 )
    {
        printf("您选择的操作是：");
        fflush(stdin);
        selectCode = getchar();
        switch (selectCode)
        {
        case '1':
            inputSL(P_SL);
            break;
        case '2':
            outputSL(P_SL, SL.length);
            break;
        case '3':
            insertSLHead(P_SL);
            break;
        case '4':
            insertSLTail(P_SL);
            break;
        case '5':
            instertSLLocation(P_SL);
            break;
        case '6':
            deleteSLHead(P_SL);
            break;
        case '7':
            deleteSLTail(P_SL);
            break;
        case '8':
            deleteSLLocation(P_SL);
            break;
        default:
            printf("您选择退出程序，欢迎下次光临！\n");
            flag = 0;                             //这里是退出，所以flag=0，这样就可以终端循环
        }
    }
    
}


