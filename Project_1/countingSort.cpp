//
// Created by macelaru on 07.03.2023.
//
# include "countingSort.h"

void countingSort(int v[], int n, int Max) {
    int *output = new int[n + 1];
    int *count = new int[Max + 1];
    for (int i = 0; i <= Max; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[v[i]]++;

    for (int i = 1; i <= Max; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[v[i]] - 1] = v[i];
        count[v[i]]--;
    }
    for (int i = 0; i < n; i++)
        v[i] = output[i];
    delete[] output;
}