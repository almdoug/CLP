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
        int resultado = A(2, 3);
        System.out.println("A(2, 3) = " + resultado);
    }
}
