// Douglas Benevides Almeida
import java.util.Arrays;

public class Main {
    static void permutacao(int[] vetor, int n, int i) {
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

    public static void main(String[] args) {
        int max_n = 2;
        long inicio, fim;
        System.out.println("Tempo de permutacao para cada n:");

        while (true) {
            int[] vetor = new int[max_n];
            for (int i = 0; i < max_n; i++) {
                vetor[i] = i + 1;
            }

            inicio = System.currentTimeMillis();
            permutacao(vetor, max_n, 0);
            fim = System.currentTimeMillis();

            double tempo = (fim - inicio) / 1000.0;
            System.out.printf("n = %d: --- %.6f segundos\n", max_n, tempo);
            if (tempo > 60.0) {
                break;
            }
            max_n++;
        }
        System.out.printf("--> n maximo em menos de 1 minuto: %d\n", max_n - 1);
    }
}