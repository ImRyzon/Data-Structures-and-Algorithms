import java.util.*;
import java.io.*;
public class QuickSort {

    public static void main(String[] args) {

        int[] array = {18290, 21567, 1267, 6, 1096739012, 671}; // Demo array
        int length = array.length;

        System.out.println("Current Array: " + Arrays.toString(array) + "\n");

        quickSort(array, 0, length - 1);

        System.out.println("Sorted Array: " + Arrays.toString(array) + "\n");
    }

    static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pivot = divide(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }

    static int divide(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);

        for(int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return (i + 1);
    }

    static void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
