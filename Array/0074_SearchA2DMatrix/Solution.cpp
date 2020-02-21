// Runtime: 4 ms, faster than 99.74% of C++ online submissions for Search a 2D Matrix.
// Memory Usage: 9.8 MB, less than 90.91% of C++ online submissions for Search a 2D Matrix.

#include <vector>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
    {
        int nRows = matrix.size();
        if (nRows == 0)
        {
            return false;
        }
        
        int nCols = matrix[0].size();
        if (nCols == 0)
        {
            return false;
        }
        
        int startRowIdx = 0;
        int endRowIdx = nRows-1;
        int startColIdx = 0;
        int endColIdx = nCols-1;
        while (startRowIdx <= endRowIdx)
        {
            int midRowIdx = startRowIdx + (endRowIdx - startRowIdx) / 2;  // prevents overflow
            if (matrix[midRowIdx][startColIdx] <= target && target <= matrix[midRowIdx][endColIdx])
            {
                while (startColIdx <= endColIdx)
                {
                    int midColIdx = startColIdx + (endColIdx - startColIdx) / 2;  // prevents overflow
                    if (target == matrix[midRowIdx][midColIdx])
                    {
                        return true;
                    }
                    else if (target < matrix[midRowIdx][midColIdx])
                    {
                        endColIdx = midColIdx - 1;
                    }
                    else
                    {
                        startColIdx = midColIdx + 1;
                    }
                }
                return false;
            }
            else if (target < matrix[midRowIdx][startColIdx])
            {
                endRowIdx = midRowIdx - 1;
            }
            else
            {
                startRowIdx = midRowIdx + 1;
            }
        }
        return false;
    }
};
