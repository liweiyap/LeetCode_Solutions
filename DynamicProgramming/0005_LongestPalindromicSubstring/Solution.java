// Your runtime beats 16.88 % of java submissions.

class Solution
{
    public String longestPalindrome(String s)
    {
        int strLen = s.length();
        if (s == null || strLen == 0)
        {
            return s;
        }

        boolean[][] truthTable = new boolean[strLen][strLen];
        int correctStartIdx = 0;
        int maxSubStrLen = 1;

        // Case 1: all individual letters are palindromes of length 1
        for (int i = 0; i < strLen; ++i)
        {
            truthTable[i][i] = true;
        }

        // Case 2: palindromes of length 2
        for (int i = 0; i < strLen-1; ++i)
        {
            if (s.charAt(i) == s.charAt(i+1))
            {
                correctStartIdx = i;
                maxSubStrLen = 2;
            }
            truthTable[i][i+1] = (s.charAt(i) == s.charAt(i+1));
        }

        // Case 3: palindromes of length >2
        for (int subStrLen = 3; subStrLen <= strLen; ++subStrLen)
        {
            for (int i = 0; i < strLen-subStrLen+1; ++i)
            {
                int j = i+subStrLen-1;
                if (truthTable[i+1][j-1] && (s.charAt(i) == s.charAt(j)))
                {
                    correctStartIdx = i;
                    maxSubStrLen = subStrLen;
                }
                truthTable[i][j] = truthTable[i+1][j-1] && (s.charAt(i) == s.charAt(j));
            }
        }

        return s.substring(correctStartIdx, correctStartIdx + maxSubStrLen);
    }
}