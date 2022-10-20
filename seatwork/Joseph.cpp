#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

// 约瑟夫环问题（使用循环单链表）

typedef struct Joseph
{
    int number;
    struct Joseph *next;
}person, *LNodeList;


person *initLink( int n)
{
    person *head = (LNodeList)malloc(sizeof(person));
    head -> number = 1;
    head -> next = NULL;
    person *cyclic = head;
    for (int i = 2; i <= n ; i++)
    {
        person *body = (LNodeList)malloc(sizeof(person));
        body -> number = i;
        body -> next = NULL;
        cyclic -> next = body;
        cyclic  = cyclic -> next;
    }
    //首尾相连
    cyclic -> next = head;
    return head;
}

void FindAndKillk( person *head, int k, int m)
{
    person * tail=head;
    //找到链表第一个结点的上一个结点，为删除操作做准备
    while (tail->next!=head) {
        tail=tail->next;
    }
    person * p=head;
    //找到编号为k的人
    while (p->number!=k) {
        tail=p;
        p=p->next;
    }
    //从编号为k的人开始，只有符合p->next==p时，说明链表中除了p结点，所有编号都出列了，
    while (p->next!=p) {
        //找到从p报数1开始，报m的人，并且还要知道数m-1de人的位置tail，方便做删除操作。
        for (int i=1; i<m; i++) {
            tail=p;
            p=p->next;
        }
        tail->next=p->next;//从链表上将p结点摘下来
        printf("出列人的编号为:%d\n",p->number);
        free(p);
        p=tail->next;//继续使用p指针指向出列编号的下一个编号，游戏继续
    }
    printf("出列人的编号为:%d\n",p->number);
    free(p);
}

int main() {
    printf("输入圆桌上的人数n:");
    int n;
    scanf("%d",&n);
    person * head=initLink(n);
    printf("从第k人开始报数(k>1且k<%d)：",n);
    int k;
    scanf("%d",&k);
    printf("数到m的人出列：");
    int m;
    scanf("%d",&m);
    FindAndKillk(head, k, m);
    return 0;
}

