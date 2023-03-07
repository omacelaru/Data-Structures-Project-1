//
// Created by macelaru on 07.03.2023.
//

#ifndef PROJECT_1_SORT_H
#define PROJECT_1_SORT_H

//####### MERGE SORT #######
void mergeArrays(int v[], int left, int m, int right);

void mergeSort(int v[], int left, int right);


//####### RADIX SORT ######
int getMax(int v[], int n);

void countSort(int v[], int n, int c);

void radixSort(int v[], int n);


//####### SHELL SORT ######
void shellSort(int v[], int n);


//####### HEAP SORT #######
void swap(int &a, int &b);

void heapify(int v[], int n, int i);

void heapSort(int v[], int n);


//####### COUNTING SORT #######
void countingSort(int v[], int n, int Max);

#endif //PROJECT_1_SORT_H
