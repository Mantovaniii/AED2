/*
Autor: Murilo Oliva Mantovani
RA: 834730
Data:24/04/2025
Descrição: Implementação do algoritmo de ordenação Radix Sort.
*/

#include <iostream>
#include <vector>

using namespace std;

//Função Counting Sort para ordenar os números com base na posição do dígito atual
void Countingsort_R(vector<int>& arr, int size, int exp) {
    vector<int> output(size);
    int count[10] = {0};


    for (int i = 0; i < size; i++)
        count[(arr[i] / exp) % 10]++;


    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];


    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }


    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

//Função principal do Radix Sort
void Radixsort(vector<int>& arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];

    for (int exp = 1; max / exp > 0; exp *= 10)
        Countingsort_R(arr, size, exp);
}

//Função para imprimir o vetor
void printArray(vector<int>& arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//Função principal
int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = arr.size();

    cout << "Vetor original: ";
    printArray(arr, size);

    Radixsort(arr, size);

    cout << "Vetor ordenado: ";
    printArray(arr, size);

    system("pause"); //Pausa o sistema para que possa visualizar os resultados

    return 0;
}

