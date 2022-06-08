//
// Created by 周舟 on 2022/6/8.
//
#include "iostream"

using namespace std;

//快速排序
void QuickSort(int a[], int low, int high)
{
    int i = low;
    int j = high;
    int x = a[low];
    while(i < j)
    {
        while(i < j && a[j] >= x)
        {
            j--;
        }
        a[i] = a[j];
        while(i < j && a[i] <= x)
        {
            i++;
        }
        a[j] = a[i];
    }
    a[i] = x;
    if(low < i - 1)
    {
        QuickSort(a, low, i - 1);
    }
    if(high > i + 1)
    {
        QuickSort(a, i + 1, high);
    }
}

int main() {
    int a[10] = {10, 2, 83, 8, 21, 6, 75, 82, 40, 100};
    QuickSort(a, 0, 9);
    for(int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}