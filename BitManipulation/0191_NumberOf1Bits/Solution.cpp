// Runtime: 4 ms, faster than 67.28% of C++ online submissions for Number of 1 Bits.
// Memory Usage: 8.3 MB, less than 65.85% of C++ online submissions for Number of 1 Bits.

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int weight = 0;
        while (n != 0)
        {
            n &= (n-1);
            ++weight;
        }
        return weight;
    }
};
