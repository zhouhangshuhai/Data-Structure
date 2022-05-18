//
// Created by 周舟 on 2022/3/31.
//
#include<iostream>

using namespace std;

int main() {
    int num[50];
    int i, j, k, m, n;
    int *p;
    cout << endl << "输入人数：" << endl;
    cin >> n;
    p = num;
    for (i = 0; i < n; i++) {
        *(p + i) = i + 1;
    }
    i = 0;
    k = 0;
    m = 0;
    while (m < n - 1)
    {
        if (*(p + i) != 0) {
            k++;
        }
        if (k == 3)
        {
            *(p + i) = 0;
            k = 0;
            m++;
        }
        i++;
        if (i == n) {
            i = 0;
        }
    }
    while (*p == 0) {
        p++;
    }
    cout << "最后一个是" << *p << "号" << endl;
    return 0;
}