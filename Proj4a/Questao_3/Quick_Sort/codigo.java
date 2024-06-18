// Douglas Benevides Almeida

public class main {
    public static void trocar(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public static int particionar(int arr[], int baixo, int alto) {
        int pivo = arr[alto];
        int i = (baixo - 1);
        for (int j = baixo; j < alto; j++) {
            if (arr[j] < pivo) {
                i++;
                trocar(arr, i, j);
            }
        }
        trocar(arr, i + 1, alto);
        return i + 1;
    }
    public static void quickSort(int arr[], int baixo, int alto) {
        if (baixo < alto) {
            int pi = particionar(arr, baixo, alto);

            quickSort(arr, baixo, pi - 1);
            quickSort(arr, pi + 1, alto);
        }
    }
    public static void imprimirArray(int arr[]) {
        for (int i : arr)
            System.out.print(i + " ");
        System.out.println();
    }
    public static void main(String args[]) {
        int arr[] = {10, 7, 8, 9, 1, 5};
        System.out.println("Array inicial:");
        imprimirArray(arr);
        quickSort(arr, 0, arr.length - 1);
        System.out.println("Array ordenado:");
        imprimirArray(arr);
    }
}
