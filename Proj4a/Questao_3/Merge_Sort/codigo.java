// Douglas Benevides Almeida

public class main {
    public static void merge(int arr[], int esq, int meio, int dir) {
        int tamEsq = meio - esq + 1;
        int tamDir = dir - meio;
        int[] EsqArr = new int[tamEsq];
        int[] DirArr = new int[tamDir];

        for (int i = 0; i < tamEsq; ++i)
            EsqArr[i] = arr[esq + i];
        for (int j = 0; j < tamDir; ++j)
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
    public static void mergeSort(int arr[], int esq, int dir) {
        if (esq < dir) {
            int meio = esq + (dir - esq) / 2;

            mergeSort(arr, esq, meio);
            mergeSort(arr, meio + 1, dir);
            merge(arr, esq, meio, dir);
        }
    }
    public static void imprimirArray(int arr[]) {
        for (int i : arr)
            System.out.print(i + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        int arr[] = {12, 11, 13, 5, 6, 7};
        System.out.println("Array inicial:");
        imprimirArray(arr);
        mergeSort(arr, 0, arr.length - 1);
        System.out.println("\nArray ordenado:");
        imprimirArray(arr);
    }
}
