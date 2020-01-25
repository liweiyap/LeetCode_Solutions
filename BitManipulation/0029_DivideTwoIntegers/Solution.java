// Runtime: 3 ms, faster than 14.91% of Java online submissions for Divide Two Integers.
// Memory Usage: 38.7 MB, less than 6.06% of Java online submissions for Divide Two Integers.

class Solution
{
    public int divide(int dividend, int divisor)
    {
        if (divisor == 1)
        {
            return dividend;
        }
        if (dividend == Integer.MIN_VALUE && divisor == -1)
        {
            return Integer.MAX_VALUE;
        }

        int dividendAbs = Math.abs(dividend);
        int divisorAbs = Math.abs(divisor);
        int quotient = 0;
        while (dividendAbs - divisorAbs >= 0)
        {
            int powerOf2 = 0;
            while (dividendAbs - (divisorAbs << 1 << powerOf2) >= 0)
            {
                ++powerOf2;
            }
            quotient += (1 << powerOf2);
            dividendAbs -= (divisorAbs << powerOf2);
        }

        return ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) ? -quotient : quotient;
    }
}