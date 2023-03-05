//
// Created by macelaru on 05.03.2023.
//

#include "mergeSort.h"

void mergeArrays(int v[], int left, int m, int right) {
    int *c, k = 1, i = left, j = m + 1;
    c = new int[right];
    while (i <= m && j <= right) {
        if (v[i] < v[j]) {
            c[k++] = v[i];
            i++;
        } else {
            c[k++] = v[j];
            j++;
        }
    }
    while (i <= m) {
        c[k++] = v[i];
        i++;
    }
    while (j <= right) {
        c[k++] = v[j];
        j++;
    }

    k = 1;
    for (i = left; i <= right; i++)
        v[i] = c[k++];
    delete[] c;
}

void mergeSort(int v[], int left, int right) {
    if (left < right) {
        int m = left + (right - left) / 2;
        mergeSort(v, left, m);
        mergeSort(v, m + 1, right);
        mergeArrays(v, left, m, right);
    }
}