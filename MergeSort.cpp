/*
Autor: Murilo Oliva Mantovani
RA: 834730
Data:08/04/2025
Descrição: Implementação do algoritmo de ordenação Insertion Sort.
*/

#include <iostream>
#include <vector>

using namespace std;

//Função para dividir o vetor em duas partes
void Merge(vector<int> &A, int low, int q, int high) {
    int nL = q - low + 1;
    int nR = high - q;

    vector<int> L(nL), R(nR);

    for (int i = 0; i < nL; i++)
        L[i] = A[low + i];
    for (int j = 0; j < nR; j++)
        R[j] = A[q + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < nL) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < nR) {
        A[k] = R[j];
        j++;
        k++;
    }
}

//Função para realizar o Merge Sort
void MergeSort(vector<int> &A, int low, int high) {
    if (low < high) {
        int q = low + (high - low) / 2;
        MergeSort(A, low, q);
        MergeSort(A, q + 1, high);
        Merge(A, low, q, high);
    }
}

//Função principal para testar o código
int main() {
    vector<int> arr = {7, 2, 9, 1, 5, 6};

    cout << "Array antes da ordenação: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    MergeSort(arr, 0, arr.size() - 1);

    cout << "Array após a ordenação: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}