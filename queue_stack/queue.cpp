//
// Created by 周舟 on 2022/4/20.
//
#include "iostream"

using namespace std;

int main() {
    //循环队列的插入和删除
    int queue[10];
    int front = 0;
    int rear = 0;
    int n;
    cout << "请输入队列的大小：";
    cin >> n;
    while (1) {
        cout << "请输入操作：1.插入 2.删除 3.退出" << endl;
        int op;
        cin >> op;
        if (op == 1) {
            if (rear == n) {
                cout << "队列已满，不能插入" << endl;
                cout << "队列为：";
                for (int i = 0; i < n; i++) {
                    cout << queue[i] << " ";
                }
                cout << endl;
            } else {
                cout << "请输入要插入的数据：";
                int data;
                cin >> data;
                queue[rear] = data;
                rear++;
            }
        } else if (op == 2) {
            if (front == rear) {
                cout << "队列已空，不能删除" << endl;
            } else {
                cout << "删除的数据为：" << queue[front] << endl;
                front++;
            }
        } else if (op == 3) {
            break;
        }
    }
    return 0;
}