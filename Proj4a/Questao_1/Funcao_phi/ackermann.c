// Douglas Benevides Almeida

#include <stdio.h>

// Definição da função phi
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
    int m, n, p;
    m = 2;
    n = 3;
    p = 2;

    printf("phi(%d, %d, %d) = %d\n", m, n, p, phi(m, n, p));

    return 0;
}
