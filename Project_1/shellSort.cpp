//
// Created by macelaru on 05.03.2023.
//
void shellSort(int v[], int n) {
    for (int itv = n / 2; itv > 0; itv /= 2) {
        for (int i = itv; i < n; i += 1) {
            int aux = v[i];
            int j;
            for (j = i; j >= itv; j -= itv) {
                if (v[j - itv] <= aux)
                    break;
                v[j] = v[j - itv];
            }
            v[j] = aux;
        }
    }
}