#include <iostream>
#include <array>;

using namespace std;

void merge(int* saida, int* auxiliar, int inicio, int meio, int fim) {
    int i, j, k;
    i = inicio;
    j = meio + 1;
    k = inicio;
    while (i <= meio && j <= fim) {
        if (auxiliar[i] < auxiliar[j]) {
            saida[k] = auxiliar[i];
            i++;
        }
        else {
            saida[k] = auxiliar[j];
            j++;
        }
        k++;
    }

    while (i <= meio) {
        saida[k] = auxiliar[i];
        i++;
        k++;
    }

    while (j <= fim) {
        saida[k] = auxiliar[j];
        j++;
        k++;
    }
    //Copia os elementos que foram ordenados para o auxiliar
    for (int p = inicio; p <= fim; p++)
        auxiliar[p] = saida[p];
}

void mergeSort(int* saida, int* auxiliar, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(saida, auxiliar, inicio, meio);
        mergeSort(saida, auxiliar, meio + 1, fim);
        merge(saida, auxiliar, inicio, meio, fim);
    }
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << A[i] << " ";
}

int main() {
    int saida;
    int auxiliar;
    int inicio;
    int fim;

    std::cout << "array desordenado: \n" << std::endl;
    printArray(arr, arr_size);

    mergeSort(int* saida, int* auxiliar, int inicio, int fim)

    std::cout << "\n array ordenado \n" << std::endl;
    printArray(arr, arr_size);
    return 0;
}
