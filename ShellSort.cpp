/*
Autor: Murilo Oliva Mantovani
RA: 834730
Data:09/04/2025
Descrição: Implementação do algoritmo de ordenação Shell Sort.
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

//Função para realizar o Shell Sort
void shellSort(vector<int> &arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int j = i;
            while (j >= gap && arr[j] < arr[j - gap]) {
                swap(arr[j], arr[j - gap]);
                j -= gap;
            }
        }
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

    shellSort(arr);

    cout << "Array após a ordenação: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    system("pause"); //Pausa o sistema para que possa visualizar os resultados

    return 0;
}