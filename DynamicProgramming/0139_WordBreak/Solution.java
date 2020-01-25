// Runtime: 25 ms, faster than 5.40% of Java online submissions for Word Break.
// Memory Usage: 44 MB, less than 5.08% of Java online submissions for Word Break.

import java.util.List;

class Solution
{
    public boolean wordBreak(String s, List<String> wordDict)
    {
        boolean[] DP = new boolean[s.length() + 1];
        DP[0] = true;

        for (int endIdx = 1; endIdx <= s.length(); ++endIdx)
        {
            for (int startIdx = 0; startIdx < endIdx; ++startIdx)
            {
                if (DP[startIdx] && wordDict.contains(s.substring(startIdx, endIdx)))
                {
                    DP[endIdx] = true;
                    continue;
                }
            }
        }

        return DP[s.length()];
    }
}