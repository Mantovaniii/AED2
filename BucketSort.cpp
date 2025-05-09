/*
Autor: Murilo Oliva Mantovani
RA: 834730
Data:08/05/2025
Descrição: Implementação do algoritmo de ordenação Bucket Sort.
*/

#include <iostream>
#include <vector>

using namespace std;

// Função sort para ordenar os elementos dentro de cada balde
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Função para realizar o Bucket Sort
void BucketSort(vector<int>& arr, int size) {
    // Encontrar o valor máximo no vetor
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // Criar os baldes
    vector<vector<int>> buckets(maxVal + 1);

    // Distribuir os elementos nos baldes
    for (int i = 0; i < size; i++) {
        buckets[arr[i]].push_back(arr[i]);
    }

    // Ordenar cada balde e concatená-los
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        if (!buckets[i].empty()) {
            insertionSort(buckets[i]);
            for (int j = 0; j < buckets[i].size(); j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

// Função para imprimir o vetor
void printArray(const vector<int>& arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Função principal
int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = arr.size();

    cout << "Vetor original: ";
    printArray(arr, size);

    BucketSort(arr, size);

    cout << "Vetor ordenado: ";
    printArray(arr, size);

    system("pause"); //Pausa o sistema para que possa visualizar os resultados

    return 0;
}