// Douglas Benevides Almeida

public class main {
    public static int A(int m, int n) {
        if (m == 0) {
            return n + 1;
        } else if (n == 0) {
            return A(m - 1, 1);
        } else {
            return A(m - 1, A(m, n - 1));
        }
    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();
        final long TEMPO_LIMITE_MILLIS = 60000;

        try {
            for (int m = 0; m <= 100; m++) {
                for (int n = 0; n <= 100; n++) {
                    int resultado = A(m, n);
                    System.out.println("A(" + m + ", " + n + ") = " + resultado);
                    long currentTime = System.currentTimeMillis();
                    if (currentTime - startTime >= TEMPO_LIMITE_MILLIS) {
                        System.out.println("Tempo limite excedido.");
                        return;
                    }
                }
            }
        } catch (Exception e) {
            System.err.println("Erro durante a execucao do programa:");
            e.printStackTrace();
        }
    }
}
