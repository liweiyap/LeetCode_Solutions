// Runtime: 5 ms, faster than 56.14% of Java online submissions for Edit Distance.
// Memory Usage: 39.1 MB, less than 37.47% of Java online submissions for Edit Distance.

import java.lang.String;
import java.lang.Boolean;

class Solution
{
    public int minDistance(String word1, String word2)
    {
        int[][] dp = new int[word1.length()+1][word2.length()+1];
        dp[0][0] = 0;

        for (int row = 0; row < word1.length(); ++row)
        {
            dp[row+1][0] = row+1;
        }

        for (int col = 0; col < word2.length(); ++col)
        {
            dp[0][col+1] = col+1;
        }

        for (int row = 0; row < word1.length(); ++row)
        {
            for (int col = 0; col < word2.length(); ++col)
            {
                // if (word1.charAt(row)==word2.charAt(col)), then delta := 1
                int delta = Boolean.compare((word1.charAt(row)==word2.charAt(col)), false);

                dp[row+1][col+1] = Math.min(dp[row][col]+1-delta,
                        Math.min(dp[row+1][col]+1, dp[row][col+1]+1));
            }
        }

        return dp[word1.length()][word2.length()];
    }
}