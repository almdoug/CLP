// Douglas Benevides Almeida

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

double medirTempoMedioBubbleSort(int tamanhoLista) {
    const int NUM_EXECUCOES = 10;
    clock_t inicio, fim;
    double tempoTotal = 0;

    for (int execucao = 0; execucao < NUM_EXECUCOES; execucao++) {
        int* arr = (int*)malloc(tamanhoLista * sizeof(int));

        // Inicializar array com números aleatórios
        for (int i = 0; i < tamanhoLista; i++) {
            arr[i] = rand() % 1000; // números entre 0 e 999
        }

        // Medir o tempo de execução do Bubble Sort
        inicio = clock();
        bubbleSort(arr, tamanhoLista);
        fim = clock();

        // Calcular tempo decorrido em segundos
        double tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        tempoTotal += tempoExecucao;

        free(arr);
    }

    // Retornar tempo médio em segundos
    return tempoTotal / NUM_EXECUCOES;
}


void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j < alto; j++) {
        if (arr[j] < pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quickSort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto);

        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

double medirTempoMedioQuickSort(int tamanhoLista) {
    const int NUM_EXECUCOES = 10;
    clock_t inicio, fim;
    double tempoTotal = 0;

    for (int execucao = 0; execucao < NUM_EXECUCOES; execucao++) {
        int* arr = (int*)malloc(tamanhoLista * sizeof(int));

        // Inicializar array com números aleatórios
        for (int i = 0; i < tamanhoLista; i++) {
            arr[i] = rand() % 1000; // números entre 0 e 999
        }

        // Medir o tempo de execução do Quick Sort
        inicio = clock();
        quickSort(arr, 0, tamanhoLista - 1);
        fim = clock();

        // Calcular tempo decorrido em segundos
        double tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        tempoTotal += tempoExecucao;

        free(arr);
    }

    // Retornar tempo médio em segundos
    return tempoTotal / NUM_EXECUCOES;
}


void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

double medirTempoMedioInsertionSort(int tamanhoLista) {
    const int NUM_EXECUCOES = 10;
    clock_t inicio, fim;
    double tempoTotal = 0;

    for (int execucao = 0; execucao < NUM_EXECUCOES; execucao++) {
        int* arr = (int*)malloc(tamanhoLista * sizeof(int));

        // Inicializar array com números aleatórios
        for (int i = 0; i < tamanhoLista; i++) {
            arr[i] = rand() % 1000; // números entre 0 e 999
        }

        // Medir o tempo de execução do Insertion Sort
        inicio = clock();
        insertionSort(arr, tamanhoLista);
        fim = clock();

        // Calcular tempo decorrido em segundos
        double tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        tempoTotal += tempoExecucao;

        free(arr);
    }

    // Retornar tempo médio em segundos
    return tempoTotal / NUM_EXECUCOES;
}

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

double medirTempoMedio(int tamanhoLista) {
    const int NUM_EXECUCOES = 10;
    clock_t inicio, fim;
    double tempoTotal = 0;

    for (int execucao = 0; execucao < NUM_EXECUCOES; execucao++) {
        int* arr = (int*)malloc(tamanhoLista * sizeof(int));

        // Inicializar array com números aleatórios
        for (int i = 0; i < tamanhoLista; i++) {
            arr[i] = rand() % 1000; // números entre 0 e 999
        }

        // Medir o tempo de execução do Merge Sort
        inicio = clock();
        mergeSort(arr, 0, tamanhoLista - 1);
        fim = clock();

        // Calcular tempo decorrido em segundos
        double tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        tempoTotal += tempoExecucao;

        free(arr);
    }

    // Retornar tempo médio em segundos
    return tempoTotal / NUM_EXECUCOES;
}

void gerarCSV() {
    FILE *arquivo;
    arquivo = fopen("result_ordenacao.csv", "w");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return;
    }

    // Tamanhos das listas a serem testadas
    int tamanhos[] = {10, 100, 1000};

    // Escrever cabeçalho no arquivo CSV
    fprintf(arquivo, "Tamanho da Lista,Bubble Sort,Quick Sort,Insertion Sort,Merge Sort\n");

    // Medir tempo médio para cada tamanho de lista e escrever no arquivo
    for (int i = 0; i < sizeof(tamanhos) / sizeof(tamanhos[0]); i++) {
        int tamanhoLista = tamanhos[i];

        double tempoMedioBubble = medirTempoMedioBubbleSort(tamanhoLista);
        double tempoMedioQuick = medirTempoMedioQuickSort(tamanhoLista);
        double tempoMedioInsertion = medirTempoMedioInsertionSort(tamanhoLista);
        double tempoMedioMerge =  medirTempoMedio(tamanhoLista);
        fprintf(arquivo, "%d,%.6f,%.6f,%.6f,%.6f\n", tamanhoLista, tempoMedioBubble, tempoMedioQuick, tempoMedioInsertion, tempoMedioMerge);
    }

    fclose(arquivo);
    printf("Arquivo gerado com sucesso.\n");
}

int main() {
    srand(time(NULL)); // inicializar semente para números aleatórios
    gerarCSV();
    return 0;
}