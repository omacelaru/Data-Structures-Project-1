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
    int *sol, count[10] = {0}, i;
    sol = new int[n];

    for (i = 0; i < n; i++)
        count[(v[i] / c) % 10]++;
    for (i = 1; i < n; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        sol[count[(v[i] / c) % 10] - 1] = v[i];
        count[(v[i] / c) % 10]--;
    }
    for (i = 0; i < n; i++)
        v[i] = sol[i];
    std::cout << "aici"<<std::endl;
    delete[] sol;
}

void radixSort(int v[], int n) {
    int Max = getMax(v, n);

    for (int c = 1; Max / c > 0; c *= 10) {
        countSort(v, n, c);
    }
}