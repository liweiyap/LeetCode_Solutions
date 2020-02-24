// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Power of Two.
// Memory Usage: 8.1 MB, less than 66.00% of C++ online submissions for Power of Two.

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return n > 0 && (n & (n-1)) == 0;
    }
};
