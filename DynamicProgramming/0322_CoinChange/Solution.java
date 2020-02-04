// Runtime: 9 ms, faster than 88.81% of Java online submissions for Coin Change.
// Memory Usage: 40.3 MB, less than 5.33% of Java online submissions for Coin Change.

import java.util.Arrays;

class Solution
{
    public int coinChange(int[] coins, int amount)
    {
        int[] dp = new int[amount+1];
        Arrays.fill(dp, amount+1);

        dp[0] = 0;  // initialise DP; 0 coins to get an amount of 0
        for (int denom : coins)
        {
            for (int partial = denom; partial <= amount; ++partial)
            {
                dp[partial] = Math.min(1+dp[partial-denom], dp[partial]);
            }
        }

        return (dp[amount] == amount+1) ? -1 : dp[amount];
    }
}