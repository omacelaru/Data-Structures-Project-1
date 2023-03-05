#include <iostream>
#include "mergeSort.h"
#include "radixSort.h"

using namespace std;

int main() {
    int v[] = {8, 3, 2, 4, 5, 21, 5, 21, 1}, n = 9;
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
    radixSort(v, n);
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}
