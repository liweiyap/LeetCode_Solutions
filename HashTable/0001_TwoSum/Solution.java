// Your memory usage beats 99.61 % of java submissions.

import java.util.HashMap;
import java.util.Map;

class Solution
{
    public int[] twoSum(int[] nums, int target)
    {
        HashMap<Integer, Integer> hash = new HashMap<Integer, Integer>();
        int output[] = new int[2];
        for (int idx = 0; idx < nums.length; ++idx)
        {
            int diff = target - nums[idx];
            for (Map.Entry<Integer, Integer> entry : hash.entrySet())
            {
                if (entry.getValue() == nums[idx])
                {
                    output[0] = entry.getKey();
                    output[1] = idx;
                    return output;
                }
            }
            hash.put(idx, diff);
        }
        return output;
    }
}
