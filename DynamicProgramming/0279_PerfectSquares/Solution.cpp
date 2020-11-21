// Runtime: 124 ms, faster than 76.60% of C++ online submissions for Perfect Squares.
// Memory Usage: 9.5 MB, less than 39.14% of C++ online submissions for Perfect Squares.

#include <cmath>

class Solution
{
public:
    int numSquares(int n)
    {
        // first, check if n is a perfect square
        double root = std::sqrt(n);
        if (root - std::floor(root) == 0.0)
        {
            return 1;
        }
        
        // else, do DP
        int* dp = new int[n+1];  // start at 0 to account for values of n that are perfect squares
        for (int i = 0; i <= n; ++i)
        {
            dp[i] = i;
        }
        // start at 4, which is the second perfect square
        for (int i = 4; i <= n; ++i)
        {
            for (int j = 1; j * j <= i; ++j)
            {
                dp[i] = min(dp[i], 1+dp[i-j*j]);
            }
        }
        
        int num = dp[n];
        delete[] dp;
        return num;
    }
};
