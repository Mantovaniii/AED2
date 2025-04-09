/*
Autor: Murilo Oliva Mantovani
RA: 834730
Data:08/04/2025
Descrição: Implementação do algoritmo de ordenação Insertion Sort.
*/

#include <iostream>
#include <vector>

using namespace std;

//Função para trocar dois elementos
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//Função para dividir o vetor em duas partes em torno de um pivô
void partition(vector<int> &arr, int low, int high, int &i, int &j) {
    i = low - 1;
    j = high + 1;
    int pivot = arr[low + (high - low) / 2];
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j) {
            return;
        }
        swap(arr[i], arr[j]);
    }
}

//Função para realizar o Quick Sort
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int i, j;
        partition(arr, low, high, i, j);
        quickSort(arr, low, j);      
        quickSort(arr, j + 1, high); 
    }
}


//Função principal para testar o código
int main(){
    vector<int> arr = {7, 2, 9, 1, 5, 6};

    cout << "Array antes da ordenação: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Array após a ordenação: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    system("pause"); //Pausa o sistema para que possa visualizar os resultados

    return 0;
}