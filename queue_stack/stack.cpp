//
// Created by 周舟 on 2022/4/6.
//
#include "iostream"

using namespace std;

int main(){
    //顺序栈的初始化，进栈，出栈，取栈顶元素，判断栈是否为空，清空栈
    int a[10];
    int top = -1;
    int n;
    cout << "请输入要进栈的数：";
    cin >> n;
    while(n != 0){
        if(top == 9){
            cout << "栈已满，不能进栈" << endl;
            break;
        }
        a[++top] = n;
        cout << "请输入要进栈的数：";
        cin >> n;
    }
    cout << "栈中元素为：";
    for(int i = 0; i <= top; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "请输入要出栈的数：";
    cin >> n;
    while(n != 0){
        if(top == -1){
            cout << "栈已空，不能出栈" << endl;
            break;
        }
        if(a[top] == n){
            top--;
        }
        cout << "请输入要出栈的数：";
        cin >> n;
    }
    cout << "栈中元素为：";
    for(int i = 0; i <= top; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "请输入要取栈顶元素的数：";
    cin >> n;
    while(n != 0){
        if(top == -1){
            cout << "栈已空，不能取栈顶元素" << endl;
            break;
        }
        if(a[top] == n){
            cout << "栈顶元素为：" << a[top] << endl;
        }
        cout << "请输入要取栈顶元素的数：";
        cin >> n;
    }
    cout << "请输入要清空栈的数：";
    cin >> n;
    while(n != 0){
        if(top == -1){
            cout << "栈已空，不能清空栈" << endl;
            break;
        }
        top--;
        cout << "请输入要清空栈的数：";
        cin >> n;
    }
    cout << "栈中元素为：";
    for(int i = 0; i <= top; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}