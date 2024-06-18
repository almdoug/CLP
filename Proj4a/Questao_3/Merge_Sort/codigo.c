// Douglas Benevides Almeida

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int esq, int meio, int dir) {
    int tamEsq = meio - esq + 1;
    int tamDir = dir - meio;
    int* EsqArr = (int*)malloc(tamEsq * sizeof(int));
    int* DirArr = (int*)malloc(tamDir * sizeof(int));

    for (int i = 0; i < tamEsq; i++)
        EsqArr[i] = arr[esq + i];
    for (int j = 0; j < tamDir; j++)
        DirArr[j] = arr[meio + 1 + j];

    int i = 0, j = 0, k = esq;

    while (i < tamEsq && j < tamDir) {
        if (EsqArr[i] <= DirArr[j]) {
            arr[k] = EsqArr[i];
            i++;
        } else {
            arr[k] = DirArr[j];
            j++;
        }
        k++;
    }
    while (i < tamEsq) {
        arr[k] = EsqArr[i];
        i++;
        k++;
    }
    while (j < tamDir) {
        arr[k] = DirArr[j];
        j++;
        k++;
    }
    free(EsqArr);
    free(DirArr);
}

void mergeSort(int arr[], int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;

        mergeSort(arr, esq, meio);
        mergeSort(arr, meio + 1, dir);

        merge(arr, esq, meio, dir);
    }
}
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int tamanhoArr = sizeof(arr) / sizeof(arr[0]);

    printf("Array inicial: \n");
    imprimirArray(arr, tamanhoArr);

    mergeSort(arr, 0, tamanhoArr - 1);

    printf("\nArray ordenado: \n");
    imprimirArray(arr, tamanhoArr);
    return 0;
}
