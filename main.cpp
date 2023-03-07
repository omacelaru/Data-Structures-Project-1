#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include "Sort.h"

using namespace std;

void copyArray(int c[], int v[], int n) {
    for (int i = 0; i < n; i++)
        c[i] = v[i];

}

int isAsc(int v[], int n) {
    for (int i = 1; i < n; i++)
        if (v[i] < v[i - 1])
            return 0;
    return 1;
}

int main() {
    srand(time(0));
    clock_t start;
    clock_t end;
    ifstream fin("input_test.in");
    int i, j, *v, *c;
    int number_tests, number_max, value_max;
    double timeMerge, timeRadix, timeShell, timeHeap, timeCount, timeIntro;
    fin >> number_tests;
    fin.get();
    for (i = 1; i <= number_tests; i++) {
        fin >> number_max >> value_max;
        v = new int[number_max];

        for (j = 0; j < number_max; j++) {
            v[j] = rand() % (value_max + 1);
        }

//####### MERGE SORT #######
        c = new int[number_max];
        copyArray(c, v, number_max);
        start = clock();
        mergeSort(c, 0, number_max - 1);
        end = clock();
        if (isAsc(c, number_max))
            timeMerge = double(end - start) / (double) CLOCKS_PER_SEC;
        delete[] c;
//####### RADIX SORT ######
        c = new int[number_max];
        copyArray(c, v, number_max);
        start = clock();
        radixSort(c, number_max);
        end = clock();
        if (isAsc(c, number_max))
            timeRadix = double(end - start) / (double) CLOCKS_PER_SEC;
        delete[] c;
//####### SHELL SORT ######
        c = new int[number_max];
        copyArray(c, v, number_max);
        start = clock();
        radixSort(c, number_max);
        end = clock();
        if (isAsc(c, number_max))
            timeShell = double(end - start) / (double) CLOCKS_PER_SEC;
        delete[] c;
//####### HEAP SORT #######
        c = new int[number_max];
        copyArray(c, v, number_max);
        start = clock();
        heapSort(c, number_max);
        end = clock();
        if (isAsc(c, number_max))
            timeHeap = double(end - start) / (double) CLOCKS_PER_SEC;
        delete[] c;
//####### COUNTING SORT #######
        c = new int[number_max];
        copyArray(c, v, number_max);
        start = clock();
        countingSort(c, number_max, value_max);
        end = clock();
        if (isAsc(c, number_max))
            timeCount = double(end - start) / (double) CLOCKS_PER_SEC;
        delete[] c;
//####### C++ INTRO SORT #######
        c = new int[number_max];
        copyArray(c, v, number_max);
        start = clock();
        sort(c, c + number_max);
        end = clock();
        if (isAsc(c, number_max))
            timeIntro = double(end - start) / (double) CLOCKS_PER_SEC;
        delete[] c;
        cout << i << endl;
        cout << number_max << " " << value_max << endl;
        cout << "M: " << timeMerge << " R: " << timeRadix << " S: " << timeShell << " H: " << timeHeap << " C: "
             << timeCount << " D: " << timeIntro << endl << endl;
        delete[] v;
    }

    fin.close();
    return 0;
}
