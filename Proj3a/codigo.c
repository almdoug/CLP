// Douglas Benevides Almeida
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void permutacao(int vetor[], int n, int i) {
    if (i == n) {
        return;
    }
    for (int j = i; j < n; j++) {
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
        permutacao(vetor, n, i + 1);
        temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp; 
    }
}

int main() {
    int max_n = 2;
    clock_t inicio, fim;
    printf("Tempo de permutacao para cada n:\n");
    while (1) {
        int vetor[max_n];
        for (int i = 0; i < max_n; i++) {
            vetor[i] = i + 1;
        }

        inicio = clock();
        permutacao(vetor, max_n, 0);
        fim = clock();

        double tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        printf("n = %d: --- %.6f segundos\n", max_n, tempo);

        if (tempo > 60.0) {
            break;
        }max_n++;
    }
    printf("--> n maximo em menos de 1 minuto: %d\n", max_n - 1);
    return 0;
}