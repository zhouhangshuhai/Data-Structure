//
// Created by 周舟 on 2022/6/8.
//
#include "iostream"

using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
};

//创建单链表
void CreateList(struct Node* &L, int n)
{
    struct Node* p;
    struct Node* s;
    L = (struct Node*)malloc(sizeof(struct Node));
    L->data = 0;
    L->next = NULL;
    p = L;
    for(int i = 1; i < n; i++)
    {
        s = (struct Node*)malloc(sizeof(struct Node));
        s->data = i;
        s->next = NULL;
        p->next = s;
        p = s;
    }
}

//销毁单链表
void DestroyList(struct Node* &L)
{
    struct Node* p;
    while(L != NULL)
    {
        p = L;
        L = L->next;
        free(p);
    }
}

//插入节点
void InsertNode(struct Node* &L, int i, int x)
{
    struct Node* p;
    struct Node* s;
    p = L;
    for(int j = 1; j < i; j++)
    {
        p = p->next;
    }
    s = (struct Node*)malloc(sizeof(struct Node));
    s->data = x;
    s->next = p->next;
    p->next = s;
}

//删除节点
void DeleteNode(struct Node* &L, int i)
{
    struct Node* p;
    struct Node* s;
    p = L;
    for(int j = 1; j < i; j++)
    {
        p = p->next;
    }
    s = p->next;
    p->next = s->next;
    free(s);
}

//遍历单链表
void TraverseList(struct Node* L)
{
    struct Node* p;
    p = L;
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

//查找节点
int SearchNode(struct Node* L, int x)
{
    struct Node* p;
    p = L;
    while(p != NULL)
    {
        if(p->data == x)
        {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

int main() {
    struct Node* L;
    int n;
    cout << "请输入链表的长度：";
    cin >> n;
    CreateList(L, n);
    TraverseList(L);
    InsertNode(L, 3, 4);
    TraverseList(L);
    DeleteNode(L, 3);
    TraverseList(L);
    cout << "请输入要查找的数据：";
    int x;
    cin >> x;
    if(SearchNode(L, x))
    {
        cout << "找到了" << endl;
    }
    else
    {
        cout << "没有找到" << endl;
    }
    DestroyList(L);
    return 0;

}