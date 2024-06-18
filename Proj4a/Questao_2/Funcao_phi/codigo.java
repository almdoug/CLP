// Douglas Benevides Almeida

import java.util.concurrent.TimeUnit;

public class main {
    public static int phi(int m, int n, int p) {
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
    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();
        long timeLimit = TimeUnit.MINUTES.toMillis(1);

        int maxM = 4, maxN = 4, maxP = 4;
        for (int m = 0; m <= maxM; m++) {
            for (int n = 0; n <= maxN; n++) {
                for (int p = 0; p <= maxP; p++) {
                    long currentTime = System.currentTimeMillis();
                    long elapsedTime = currentTime - startTime;
                    if (elapsedTime > timeLimit) {
                        System.out.println("Tempo limite excedido.");
                        return;
                    }
                    int result = phi(m, n, p);
                    System.out.printf("phi(%d, %d, %d) = %d%n", m, n, p, result);
                }
            }
        }
    }
}
