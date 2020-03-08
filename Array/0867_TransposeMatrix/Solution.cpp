// Runtime: 24 ms, faster than 91.17% of C++ online submissions for Transpose Matrix.
// Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Transpose Matrix.

#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& A)
    {
        std::vector<std::vector<int>> At(A[0].size(), std::vector<int>(A.size()));
        for (int y = 0; y < A.size(); ++y)
        {
            for (int x = 0; x < A[0].size(); ++x)
            {
                At[x][y] = A[y][x];
            }
        }
        return At;
    }
};
