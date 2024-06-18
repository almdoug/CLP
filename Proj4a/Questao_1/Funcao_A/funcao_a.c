// Douglas Benevides Almeida

#include <stdio.h>
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
    int resultado = A(2, 2);
    printf("A(2, 3) = %d\n", resultado);

    return 0;
}
