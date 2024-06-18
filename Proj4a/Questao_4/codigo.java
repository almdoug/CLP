// Douglas Benevides Almeida

import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class main {

    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }

    public static double medirTempoMedioBubbleSort(int tamanhoLista) {
        final int NUM_EXECUCOES = 10;
        long inicio, fim;
        double tempoTotal = 0;

        for (int execucao = 0; execucao < NUM_EXECUCOES; execucao++) {
            int[] arr = new int[tamanhoLista];

            Random random = new Random();
            for (int i = 0; i < tamanhoLista; i++) {
                arr[i] = random.nextInt(1000); // números entre 0 e 999
            }

            inicio = System.nanoTime();
            bubbleSort(arr);
            fim = System.nanoTime();

            double tempoExecucao = (fim - inicio) / 1e9; // converter para segundos
            tempoTotal += tempoExecucao;
        }

        return tempoTotal / NUM_EXECUCOES;
    }

    public static void quickSort(int[] arr, int baixo, int alto) {
        if (baixo < alto) {
            int pi = particionar(arr, baixo, alto);

            quickSort(arr, baixo, pi - 1);
            quickSort(arr, pi + 1, alto);
        }
    }

    private static int particionar(int[] arr, int baixo, int alto) {
        int pivo = arr[alto];
        int i = (baixo - 1);

        for (int j = baixo; j < alto; j++) {
            if (arr[j] < pivo) {
                i++;
                trocar(arr, i, j);
            }
        }
        trocar(arr, i + 1, alto);
        return (i + 1);
    }

    private static void trocar(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static double medirTempoMedioQuickSort(int tamanhoLista) {
        final int NUM_EXECUCOES = 10;
        long inicio, fim;
        double tempoTotal = 0;

        for (int execucao = 0; execucao < NUM_EXECUCOES; execucao++) {
            int[] arr = new int[tamanhoLista];

            // Inicializar array com números aleatórios
            Random random = new Random();
            for (int i = 0; i < tamanhoLista; i++) {
                arr[i] = random.nextInt(1000); // números entre 0 e 999
            }

            // Medir o tempo de execução do Quick Sort
            inicio = System.nanoTime();
            quickSort(arr, 0, tamanhoLista - 1);
            fim = System.nanoTime();

            // Calcular tempo decorrido em segundos
            double tempoExecucao = (fim - inicio) / 1e9; // converter para segundos
            tempoTotal += tempoExecucao;
        }

        // Retornar tempo médio em segundos
        return tempoTotal / NUM_EXECUCOES;
    }

    public static void insertionSort(int[] arr) {
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    public static double medirTempoMedioInsertionSort(int tamanhoLista) {
        final int NUM_EXECUCOES = 10;
        long inicio, fim;
        double tempoTotal = 0;

        for (int execucao = 0; execucao < NUM_EXECUCOES; execucao++) {
            int[] arr = new int[tamanhoLista];

            // Inicializar array com números aleatórios
            Random random = new Random();
            for (int i = 0; i < tamanhoLista; i++) {
                arr[i] = random.nextInt(1000); // números entre 0 e 999
            }

            // Medir o tempo de execução do Insertion Sort
            inicio = System.nanoTime();
            insertionSort(arr);
            fim = System.nanoTime();

            // Calcular tempo decorrido em segundos
            double tempoExecucao = (fim - inicio) / 1e9; // converter para segundos
            tempoTotal += tempoExecucao;
        }

        // Retornar tempo médio em segundos
        return tempoTotal / NUM_EXECUCOES;
    }

    public static void mergeSort(int[] arr, int esq, int dir) {
        if (esq < dir) {
                        int meio = esq + (dir - esq) / 2;

            mergeSort(arr, esq, meio);
            mergeSort(arr, meio + 1, dir);

            merge(arr, esq, meio, dir);
        }
    }

    private static void merge(int[] arr, int esq, int meio, int dir) {
        int tamEsq = meio - esq + 1;
        int tamDir = dir - meio;
        int[] EsqArr = new int[tamEsq];
        int[] DirArr = new int[tamDir];

        for (int i = 0; i < tamEsq; i++)
            EsqArr[i] = arr[esq + i];
        for (int j = 0; j < tamDir; j++)
            DirArr[j] = arr[meio + 1 + j];

        int i = 0, j = 0, k = esq;

        while (i < tamEsq && j < tamDir) {
            if (EsqArr[i] <= DirArr[j]) {
                arr[k] = EsqArr[i];
                i++;
            } else {
                arr[k] = DirArr[j];
                j++;
            }
            k++;
        }
        while (i < tamEsq) {
            arr[k] = EsqArr[i];
            i++;
            k++;
        }
        while (j < tamDir) {
            arr[k] = DirArr[j];
            j++;
            k++;
        }
    }

    public static double medirTempoMedioMergeSort(int tamanhoLista) {
        final int NUM_EXECUCOES = 10;
        long inicio, fim;
        double tempoTotal = 0;

        for (int execucao = 0; execucao < NUM_EXECUCOES; execucao++) {
            int[] arr = new int[tamanhoLista];

            Random random = new Random();
            for (int i = 0; i < tamanhoLista; i++) {
                arr[i] = random.nextInt(1000); // números entre 0 e 999
            }

            // Medir o tempo de execução do Merge Sort
            inicio = System.nanoTime();
            mergeSort(arr, 0, tamanhoLista - 1);
            fim = System.nanoTime();

            double tempoExecucao = (fim - inicio) / 1e9; // converter para segundos
            tempoTotal += tempoExecucao;
        }

        // Retornar tempo médio em segundos
        return tempoTotal / NUM_EXECUCOES;
    }

    public static void gerarCSV() {
        String arquivoCSV = "result_ordenacao.csv";

        try (FileWriter writer = new FileWriter(arquivoCSV)) {
            // Tamanhos das listas a serem testadas
            int[] tamanhos = {10, 100, 1000};

            // Escrever cabeçalho no arquivo CSV
            writer.append("Tamanho da Lista,Bubble Sort,Quick Sort,Insertion Sort,Merge Sort\n");

            // Medir tempo médio para cada tamanho de lista e escrever no arquivo
            for (int tamanhoLista : tamanhos) {
                double tempoMedioBubble = medirTempoMedioBubbleSort(tamanhoLista);
                double tempoMedioQuick = medirTempoMedioQuickSort(tamanhoLista);
                double tempoMedioInsertion = medirTempoMedioInsertionSort(tamanhoLista);
                double tempoMedioMerge = medirTempoMedioMergeSort(tamanhoLista);
                writer.append(String.format("%d,%.6f,%.6f,%.6f,%.6f\n", tamanhoLista, tempoMedioBubble, tempoMedioQuick, tempoMedioInsertion, tempoMedioMerge));
            }

            System.out.println("Arquivo " + arquivoCSV + " gerado com sucesso.");

        } catch (IOException e) {
            System.err.println("Erro ao escrever o arquivo CSV: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        // Inicializar semente para números aleatórios
        Random random = new Random();

        // Gerar CSV
        gerarCSV();
    }
}
