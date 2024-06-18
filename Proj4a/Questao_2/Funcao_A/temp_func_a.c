// Douglas Benevides Almeida

#include <stdio.h>
#include <time.h>

// Função A de Peter e Robinson
int A(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return A(m - 1, 1);
    } else {
        return A(m - 1, A(m, n - 1));
    }
}

int main() {
    clock_t start_time = clock();
    int m, n;
    
    // Calcular os valores possíveis em um tempo razoável
    for (m = 0; m <= 100; m++) {
        for (n = 0; n <= 100; n++) {
            int resultado = A(m, n);
            printf("A(%d, %d) = %d\n", m, n, resultado);
                        clock_t current_time = clock();
            double elapsed_time = (double)(current_time - start_time) / CLOCKS_PER_SEC;
            if (elapsed_time >= 60.0) {
                printf("Tempo limite excedido. Encerrando o programa.\n");
                return 0;
            }
        }
    }
    return 0;
}
