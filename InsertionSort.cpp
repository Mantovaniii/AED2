/*
Autor: Murilo Oliva Mantovani
RA: 834730
Data:08/04/2025
Descrição: Implementação do algoritmo de ordenação Insertion Sort.
*/

#include <iostream>
#include <vector>

using namespace std;

// Função para trocar dois elementos
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Função para realizar o Insertion Sort
void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            --j;
        }
    }
}

// Função principal para testar o código
int main() {
    vector<int> arr = {9, 8, 1, 3, 2, 5};

    cout << "Array antes da ordenação: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    insertionSort(arr);

    cout << "Array após a ordenação: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    system("pause"); //Pausa o sistema para que possa visualizar os resultados

    return 0;
}