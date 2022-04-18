public class RotateMatrix90Degrees {
    static int[][] rotateMatrix (int[][] matrix) {
        int size = matrix.length;
        for (int i = 0; i < size/2; i++) {
            for (int j = 0; j < size-j-1; j++) {
                int temp = matrix[i][j];
                matrix[j][i] = matrix[size-i-1][j];
                matrix[size-i-1][j] = matrix[size-j-1][size-i-1];
                matrix[size-j-1][size-i-1] = matrix[i][size-j-1];
                matrix[i][size-j-1] = temp;
            }
        }
        return matrix;
    }
}
