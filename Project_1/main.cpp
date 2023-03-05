#include <iostream>
#include <fstream>
#include <ctime>
#include "mergeSort.h"
#include "radixSort.h"
#include "shellSort.h"

using namespace std;

void copyArray(int c[], int v[], int n) {
    for (int i = 0; i < n; i++)
        c[i] = v[i];

}
int isAsc(int v[], int n){
    for(int i = 1; i < n; i++)
        if(v[i] < v[i-1])
            return 0;
    return 1;
}

int main() {
    srand(time(0));
    clock_t start;
    clock_t end;
    ifstream fin("input_test.in");
    ofstream g("out.out");
    int i, j, *v, *c;
    int number_tests, number_max, value_max;
    double timeMerge, timeRadix, timeShell;
    fin >> number_tests;
    fin.get();
    for (i = 1; i <= number_tests; i++) {
        fin >> number_max >> value_max;
        v = new int[number_max];
        c = new int[number_max];
        for (j = 0; j < number_max; j++) {
            v[j] = rand() % (value_max + 1);
            g << v[j] << endl;
        }
        g << endl;

        copyArray(c, v, number_max);
        start = clock();
        shellSort(c, number_max);
        end = clock();
        if(isAsc(c,number_max))
            timeRadix = double (end - start) / (double) CLOCKS_PER_SEC;
        else
            cout<<"nu e bun";

        cout << i << endl;
        cout << number_max << " " << value_max << endl;
        cout << timeRadix << endl << endl;
        delete[] c;
        delete[] v;
    }


    fin.close();
    return 0;
}
