//
// Created by macelaru on 05.03.2023.
//
#include <iostream>

int getMax(int v[], int n) {
    int Max = v[0];
    for (int i = 1; i < n; i++)
        if (Max < v[i])
            Max = v[i];
    return Max;
}

void countSort(int v[], int n, int c) {
    int *output = new int[n + 1];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(v[i] / c) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(v[i] / c) % 10] - 1] = v[i];
        count[(v[i] / c) % 10]--;
    }

    for (int i = 0; i < n; i++)
        v[i] = output[i];
    delete[] output;
}

void radixSort(int v[], int n) {
    int Max = getMax(v, n);

    for (int c = 1; Max / c > 0; c *= 10) {
        countSort(v, n, c);
    }
}