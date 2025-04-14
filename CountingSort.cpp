/*
Autor: Murilo Oliva Mantovani
RA: 834730
Data:14/04/2025
Descrição: Implementação do algoritmo de ordenação Counting Sort.
*/

#include <iostream>
#include <vector>

using namespace std;

// Função para realizar o Counting Sort
void countingSort(vector<int> &arr) {
    int n = arr.size();
    if (n == 0) return; // Se o vetor estiver vazio, não faz nada

    // Encontrar o valor máximo no vetor
    int maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // Criar um vetor de contagem
    vector<int> count(maxVal + 1, 0);

    // Contar a ocorrência de cada elemento
    for (int i = 0; i < n; ++i) {
        count[arr[i]]++;
    }

    // Reescrever o vetor original com os elementos ordenados
    int index = 0;
    for (int i = 0; i <= maxVal; ++i) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
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

    countingSort(arr);

    cout << "Array após a ordenação: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    system("pause"); //Pausa o sistema para que possa visualizar os resultados

    return 0;
}