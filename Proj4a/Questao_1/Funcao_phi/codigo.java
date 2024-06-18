// Douglas Benevides Almeida

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
        int m = 2;
        int n = 3;
        int p = 2;
        System.out.println("phi(" + m + ", " + n + ", " + p + ") = " + phi(m, n, p));
    }
}
