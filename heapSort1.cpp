//
// Created by macelaru on 07.03.2023.
//

# include "Sort.h"

void swap(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

void heapify(int v[], int n, int i) {

    int L = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && v[l] > v[L])
        L = l;

    if (r < n && v[r] > v[L])
        L = r;

    if (L != i) {
        swap(v[i], v[L]);

        heapify(v, n, L);
    }
}

void heapSort(int v[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}