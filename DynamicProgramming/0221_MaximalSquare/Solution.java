// Runtime: 3 ms, faster than 98.14% of Java online submissions for Maximal Square.
// Memory Usage: 41.9 MB, less than 83.81% of Java online submissions for Maximal Square.

import java.lang.Character;
import java.lang.Math;

class Solution
{
    public int maximalSquare(char[][] matrix)
    {
        int[][] sumMatrix = new int[matrix.length][matrix[0].length];

        // first row of DP matrix
        for (int col = 0; col < matrix[0].length; ++col)
        {
            sumMatrix[0][col] = Character.getNumericValue(matrix[0][col]);
        }

        // first column of DP matrix
        for (int row = 0; row < matrix.length; ++row)
        {
            sumMatrix[row][0] = Character.getNumericValue(matrix[row][0]);
        }

        // rest of DP matrix
        for (int row = 1; row < matrix.length; ++row)
        {
            for (int col = 1; col < matrix[0].length; ++col)
            {
                if (matrix[row][col] == '1')
                {
                    sumMatrix[row][col] = 1 + Math.min(sumMatrix[row-1][col-1],
                            Math.min(sumMatrix[row][col-1], sumMatrix[row-1][col]));
                }
                else
                {
                    sumMatrix[row][col] = 0;
                }
            }
        }

        // read max of DP matrix
        int maxDim = 0;
        for (int row = 0; row < sumMatrix.length; ++row)
        {
            for (int col = 0; col < sumMatrix[0].length; ++col)
            {
                maxDim = Math.max(maxDim, sumMatrix[row][col]);
            }
        }

        return maxDim * maxDim;
    }
}