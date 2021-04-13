// Runtime: 1 ms, faster than 98.76% of Java online submissions for Find the Difference.
// Memory Usage: 37 MB, less than 99.17% of Java online submissions for Find the Difference.

import java.lang.String;

class Solution
{
    public char findTheDifference(String s, String t)
    {
        char val = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            val ^= s.charAt(i);
        }
        for (int j = 0; j < t.length(); ++j)
        {
            val ^= t.charAt(j);
        }
        return val;
    }
}