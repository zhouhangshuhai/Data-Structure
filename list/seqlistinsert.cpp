#include <stdio.h>
#include "iostream"

using namespace std;

#define size 100

typedef struct {
    int data[size];
    int length;
} seqlist;

int LocateElem(seqlist L, int x) {
    int i;
    for (i = 0; i < L.length; ++i) {
        if (x < L.data[i]) {
            return i;
        }
    }
//    return 0;
}

int insert(seqlist &L, int x) {
    int p, i;
    p = LocateElem(L, x);
    for (i = L.length - 1; p <= i; --i) {
        L.data[i + 1] = L.data[i];
    }
    L.data[p] = x;
    ++(L.length);
    return 0;
}

int main() {
    int a;
    cin >> a;
    seqlist seqlist = {{1, 3, 6, 9}, 4};
    insert(seqlist, a);
    for (int i = 0; i < seqlist.length; ++i) {
        printf("%d\t", seqlist.data[i]);
    }
    return 0;
}
