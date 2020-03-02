// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Bits.
// Memory Usage: 7.5 MB, less than 100.00% of C++ online submissions for Reverse Bits.

class Solution
{
public:
    uint32_t reverseBits(uint32_t fwd)
    {
        int bitNum = 31;
        uint32_t rev = fwd;
        fwd >>= 1;  // we already set bitNum to 31 and not to 32
        while (fwd)
        {
            rev <<= 1;
            rev |= (fwd & 1);
            fwd >>= 1;
            --bitNum;
        }
        return rev << bitNum;  // left shift by 32 (in the edge case of all 0s) throws error, so max shift is by 31
    }
};
