public class BinarySearch {
    static int binarySearch (int array[], int start, int end, int element) {
        if (end >= 1) {
            int mid = start + (end-1) / 2;
            if (array[mid] == element) return mid;
            if (array[mid] > element) return binarySearch(array, start, mid - 1, element);
            return binarySearch(array, mid + 1, end, element);
        }
        return -1; // element not found
    }
}
