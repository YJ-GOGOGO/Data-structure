#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define MAX 200
#define BIG 999999  // 表示无穷

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
    printf("\t\t\t欢迎进入图操作界面！\n");
    printf("\t 从键盘输入数字，完成对应的操作（1到4为有效操作，输入其他退出程序）\n  ");
    printf("\t 1.图的初始化\n");
    printf("\t 2.为图赋权值，构造网\n");
    printf("\t 3.输出网的邻接矩阵\n");
    printf("\t 4.输出最小生成树\n");
    printStart();
}


typedef struct graph
{
    int vexs[MAX];                  //顶点的集合
    int edgnum[MAX];                //边的权值集合
    int matrix[MAX][MAX];           //邻接矩阵
    int end;
    int len;
}Graph;

Graph minedg[MAX+1];
int a = 0;

// 图的初始化
Graph* NewConstruct()
{
    int i, j;
    Graph *g;
    g = (Graph *)malloc(sizeof(Graph));
    if (g == NULL)
    {
        return NULL;
    }
    for ( i = 0; i < a; i++)                       //为图赋值，主对角线为0，其余为无穷
    {
        for ( j = 0; j < a; j++)
        {
            if ( i == j )
            {
                g -> matrix[i][j] = 0;
            }
            else
            {
                g -> matrix[i][j] = BIG;
                g -> matrix[j][i] = g -> matrix[i][j];
            }
        }
    }
    return g;
}

Graph* input(Graph* g)               //为1图赋权值，构造网
{
    int i = 0, j = 2;
    while (j==2)
    {
        printf("\t输入边的起点：V");
        fflush(stdin);
        scanf("%d", &g -> vexs[i]);
        printf("\t请输入边的终点：v");
        fflush(stdin);
        scanf("%d", &g -> vexs[i+1]);
        printf("\t请输入边的权值：");
        fflush(stdin);
        scanf("%d", &g -> edgnum[i]);
        g -> matrix[g -> vexs[i]][g -> vexs[i+1]] = g -> edgnum[i];
        g -> matrix[g -> vexs[i+1]][g -> vexs[i]] = g -> matrix[g -> vexs[i]][g -> vexs[i+1]];
        i++;
        printf("\t继续输入请按2，按其他任意键结束边的输入：");
        fflush(stdin);
        scanf("%d", &j);
    }
    return g;
}

void show(Graph* g)                 //输出网的邻接矩阵
{
    int i, j, sum = 0;
    printf("\t\t");
    for ( i = 0; i < a; i++)
    {
        printf("V%d\t", i);
    }
    printf("\n");
    for ( j = 0; j < a; j++)
    {
        printf("\tV%d\t", j);
        for ( i = 0; i < a; i++)
        {
            printf("%d\t", g -> matrix[j][i]);
            sum++;
            if (sum % a ==0)
            {
                printf("\n");
            }
        }
    }
}

// 从顶点u出发，构造最小生成树
void Prim(Graph* g, int u)
{
    int v, k, j, min;
    for ( v = 0; v <= a; v++)           //初始化，构造初始化候选集
        if (v != u)
        {
            minedg[v].end = u;
            minedg[v].len = g -> matrix[v][u];
        }
    minedg[u].len = 0;                 //顶点u并入集合，边权置0防止重复选取
    for ( k = 1; k < a; k++)           //依次找n-1条最短边
    {
        min = minedg[k].len;
        v = k;
        for ( j = 1; j <= a; j++)      //在候选边集中找最短边
            if (minedg[j].len > 0 && minedg[j].len < min)
            {
                min = minedg[j].len;
                v = j;
            }
        if (min == BIG)
        {
            printf("\t图不连通，无生成树！");
        }
        printf("\tV%d--V%d,其边的权值为%d：\n", v, minedg[v].end, minedg[v].len);
        minedg[v].len = -minedg[v].len;    //顶点v并入集合u，边权置负避免候选
        for ( j = 1; j <= a; j++)          //调整候选边集
            if (g -> matrix[j][v] < minedg[j].len)
            {
                minedg[j].len = g -> matrix[j][v];
                minedg[j].end = v;
            }  
    }
    printf("\t最小生成树创建成功！\n");
}

int main()
{
    int q, select, flag = 1;
    Graph *g;
    g = (Graph*)malloc(sizeof(Graph));
    menu();
    while (flag == 1)
    {
        printf("您选择的操作是：");
        fflush(stdin);
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            printf("\t请输入顶点总数：");
            fflush(stdin);
            scanf("%d", &a);
            g = NewConstruct();
            printf("\t初始化图成功！\n\n");
            break;
        case 2:
            g = input(g);
            printf("\n\n");
            break;
        case 3:
            printf("\t网的邻接矩阵为：\n");
            show(g);
            printf("\n\n");
            break;
        case 4:
            printf("\t请输入以哪位顶点作为最小生成树的根：V");
            fflush(stdin);
            scanf("%d", &q);
            Prim(g, q);
            printf("\n\n");
            break;
        default:printf("您选择退出程序，欢迎下次光临！\n");
            flag = 0;
        }
    }
    

}





