#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

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
    printf("\t\t\t欢迎进入二叉树操作界面！\n");
    printf("\t 从键盘输入数字，完成对应的操作（1到5为有效操作，输入其他退出程序）\n  ");
    printf("\t 1.将已知的先序字符序列输入建立二叉树\n");
    printf("\t 2.先序遍历二叉树并输出遍历字符序列\n");
    printf("\t 3.中序遍历二叉树并输出遍历字符序列\n");
    printf("\t 4.后序遍历二叉树并输出遍历字符序列\n");
    printf("\t 5.求叶子结点的个数\n");
    printf("\t 6.求二叉树的深度\n");
    printStart();
}

typedef char datatype;
datatype a[100];
int count=0, w, depth, ld, rd;

// 定义二叉树的结点结构
typedef struct BiTNode
{
    datatype data;
    struct BiTNode *Lchild;
    struct BiTNode *Rchild;
}BiNode, *Bitree;

// 创建二叉树
Bitree creat()
{
    Bitree bt;
    datatype ch;
    ch = a[w];
    w++;
    if (ch == ',')
    {
        return NULL;
    }
    else
    {
        bt = (Bitree)malloc(sizeof(BiNode));
        bt -> data = ch;
        bt -> Lchild = creat();
        bt -> Rchild = creat();
    }
    return bt;
}

// 先序遍历二叉树并输出字符序列
void Inorder1(Bitree bt)
{
    if (bt != NULL)
    {
        // 输出结点的值
        printf("%c  ", bt -> data);
        // 遍历二叉树的左子树
        Inorder1( bt -> Lchild );
        // 遍历二叉树的右子树
        Inorder1( bt -> Rchild );
    }
    else return;
}

// 中序遍历二叉树并输出字符序列
void Inorder2(Bitree bt)
{
    if (bt != NULL)
    {
        // 先遍历左子树
        Inorder2( bt -> Lchild );
        // 输出根节点的值
        printf("%c  ", bt -> data);
        // 再遍历右子树
        Inorder2( bt -> Rchild );
    }
    else return;
}

// 后序遍历二叉树输出遍历字符序列
void Postorder(Bitree bt)
{
    if (bt != NULL )
    {
        // 先遍历左子树
        Postorder( bt -> Lchild );
        // 再遍历右子树
        Postorder( bt -> Rchild );
        // 输出根节点的值
        printf("%c  ", bt -> data );
    }
    else return;
}


// 求叶子结点的个数
void leafcount(Bitree bt)
{
    if (bt != NULL )
    {
        count++;
        // 遍历左子树
        leafcount( bt -> Lchild );
        // 遍历右子树
        leafcount( bt -> Rchild );
    }
    else return; 
}


// 求二叉树的深度
int Treedepth(Bitree bt)
{
    if ( bt == NULL )
    {
        return 0;
    }
    else
    {
        // 遍历左子树的最大深度
        ld = Treedepth( bt -> Lchild );
        // 遍历右子树的最大深度
        rd = Treedepth( bt -> Rchild );
        // 做出判断相比左右子树的深度
        return (ld > rd ? ld : rd ) + 1;
    }
}

int main()
{
    int select, maxDepth, flag=1;
    Bitree p;
    p = (Bitree)malloc(sizeof(BiNode));
    menu();
    while (flag==1)
    {
        printf("您选择的操作是：");
        fflush(stdin);
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            printf("请输入已知的先序字符序列，如“abc, de, g..f... ” : ");
            fflush(stdin);
            gets_s(a);
            w = 0;
            p = creat();
            printf("建立二叉树成功!\n\n");
            break;
        case 2:
            printf("先序遍历二叉树并输出遍历的字符序列为：");
            Inorder1(p);
            printf("\n\n");
            break;
        case 3:
            printf("中序遍历二叉树并输出遍历的字符序列为：");
            Inorder2(p);
            printf("\n\n");
            break;
        case 4:
            printf("后序遍历二叉树并输出遍历的字符序列为：");
            Postorder(p);
            printf("\n\n");
            break;
        case 5:
            leafcount(p);
            printf("这颗二叉树的结点个数为%d\n", count);
            break;
        case 6:
            printf("二叉树的最大深度为：%d\n", Treedepth(p));
            break;
        default:
            printf("退出程序！");
            flag = 0;
            break;
        }
    }
    printf("\n");
    
}
