public class Kadanes {
    static int kadanes (int array[], int size) {
        int maxCur = array[0], maxEnd = 0;
        for (int i = 0; i < size; i++) {
            maxEnd += array[i];
            if (maxEnd < 0) maxEnd = 0;
            else if (maxCur < maxEnd) maxCur = maxEnd;
        }
        return maxCur;
    }
}
