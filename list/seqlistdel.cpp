//
// Created by 周舟 on 2022/3/30.
//
#include <stdio.h>
#include "iostream"

using namespace std;

#define size 100

typedef struct {
    int data[size];
    int length;
} seqlist;

int DeleteElem(seqlist &L,int x,int &e)
{
    if(x<0||x>=L.length)  return 0;//判断x的值是否有效
    int p,i;
    p=x;
    e=L.data[x];
    for(i=p+1;i<=L.length;i++)//左移
    {
        L.data[i-1]=L.data[i];
    }
    --(L.length);

    return e;
}

int main()
{
    int e;
    int a;
    cin>>a;
    seqlist sqlist1={{1,3,6,9},4};
    e=DeleteElem(sqlist1,a,e);
    printf("%d\n",e);

    for(int i=0;i<sqlist1.length;i++)
    {
        printf("%d\t",sqlist1.data[i]);
    }

    return 0;

}