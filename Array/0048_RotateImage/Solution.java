// Runtime: 0 ms, faster than 100.00% of Java online submissions for Rotate Image.
// Memory Usage: 39.9 MB, less than 5.77% of Java online submissions for Rotate Image.

class Solution
{
    public void rotate(int[][] matrix)
    {
        int n = matrix.length;
        int jMax = (n % 2 == 0) ? n/2-1 : n/2;

        for (int i = 0; i < n/2; ++i)
        {
            for (int j = 0; j <= jMax; ++j)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
    }
}