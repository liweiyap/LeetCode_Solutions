// Runtime: 5 ms, faster than 64.63% of Java online submissions for Task Scheduler.
// Memory Usage: 42.5 MB, less than 5.88% of Java online submissions for Task Scheduler.

import java.util.Arrays;

class Solution
{
    public int leastInterval(char[] tasks, int n)
    {
        int[] letterFreq = new int[26];
        for (char task : tasks)
        {
            ++letterFreq[task-'A'];
        }
        Arrays.sort(letterFreq);
        int totalTime = 0;
        while (letterFreq[25] > 0)
        {
            int coolingTime = 0;
            for (int idx = 25; idx >= 25-n; --idx)
            {
                if (idx >= 0 && letterFreq[idx] > 0)
                {
                    --letterFreq[idx];
                }
                ++coolingTime;
                if (letterFreq[25] == 0 || coolingTime == n+1)
                {
                    idx = 25-n-1;
                }
            }
            totalTime += coolingTime;
            Arrays.sort(letterFreq);
        }
        return totalTime;
    }
}
