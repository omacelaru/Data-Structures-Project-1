//
// Created by macelaru on 05.03.2023.
//

#include "Sort.h"

void mergeArrays(int v[], int left, int m, int right) {
    int i, j, k;
    int nl = m - left + 1;
    int nr = right - m;

    int *L = new int[nl];
    int *R = new int[nr];

    for (i = 0; i < nl; i++)
        L[i] = v[left + i];
    for (j = 0; j < nr; j++)
        R[j] = v[m + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < nl && j < nr) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < nl) {
        v[k++] = L[i];
        i++;
    }

    while (j < nr) {
        v[k++] = R[j];
        j++;
    }
    delete[] L;
    delete[] R;
}

void mergeSort(int v[], int left, int right) {
    if (left < right) {
        int m = left + (right - left) / 2;
        mergeSort(v, left, m);
        mergeSort(v, m + 1, right);
        mergeArrays(v, left, m, right);
    }
}