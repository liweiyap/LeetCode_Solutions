// Runtime: 1 ms, faster than 83.69% of Java online submissions for Pow(x, n).
// Memory Usage: 38.7 MB, less than 5.88% of Java online submissions for Pow(x, n).

class Solution
{
    public double myPow(double x, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        // divide and conquer to reduce computational complexity
        double temp = myPow(x, n/2);
        if (n % 2 == 0)
        {
            return temp * temp;
        }
        else
        {
            if (n > 0)
            {
                return temp * temp * x;
            }
            else
            {
                return temp * temp / x;
            }
        }
    }
}