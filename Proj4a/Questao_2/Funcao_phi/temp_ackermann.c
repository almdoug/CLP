// Douglas Benevides Almeida

#include <stdio.h>
#include <time.h>

int phi(int m, int n, int p) {
    if (p == 0) {
        return m + n;
    } else if (n == 0 && p == 1) {
        return 0;
    } else if (n == 0 && p == 2) {
        return 1;
    } else if (n == 0 && p > 2) {
        return m;
    } else if (n > 0 && p > 0) {
        return phi(m, phi(m, n - 1, p), p - 1);
    }
    return -1;
}

int main() {
    clock_t start_time = clock();
    double time_limit = 60.0; 

    int max_m = 4, max_n = 4, max_p = 4;

    for (int m = 0; m <= max_m; m++) {
        for (int n = 0; n <= max_n; n++) {
            for (int p = 0; p <= max_p; p++) {
                clock_t current_time = clock();
                double elapsed_time = (double)(current_time - start_time) / CLOCKS_PER_SEC;
                if (elapsed_time > time_limit) {
                    printf("Tempo limite excedido.\n");
                    return 0;
                }
                int result = phi(m, n, p);
                printf("phi(%d, %d, %d) = %d\n", m, n, p, result);
            }
        }
    }
    return 0;
}
