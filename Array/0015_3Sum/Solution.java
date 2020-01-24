// Runtime: 32 ms, faster than 64.92% of Java online submissions for 3Sum.
// Memory Usage: 56.2 MB, less than 5.29% of Java online submissions for 3Sum.

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution
{
    public List<List<Integer>> threeSum(int[] nums)
    {
        List<List<Integer>> allTriplets = new ArrayList<List<Integer>>();
        if (nums.length < 3)
        {
            return allTriplets;
        }

        Arrays.sort(nums);
        int l;
        int r;
        int sum;
        for (int i = 0; i < nums.length - 1; ++i)
        {
            l = i + 1;
            r = nums.length - 1;
            while (l < r)
            {
                sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    allTriplets.add(Arrays.asList(nums[i], nums[l], nums[r]));
                    ++l;
                    --r;

                    // skip same values nearby (no need for hash table)
                    while (l < r && nums[l] == nums[l-1])
                    {
                        ++l;
                    }

                    // skip same values nearby (no need for hash table)
                    while (l < r && nums[r] == nums[r+1])
                    {
                        --r;
                    }
                }
                else if (sum < 0)
                {
                    ++l;  // array already sorted
                }
                else
                {
                    --r;  // array already sorted
                }
            }

            // skip same values nearby (no need for hash table)
            while (i < nums.length - 1 && nums[i] == nums[i+1])
            {
                ++i;
            }
        }

        return allTriplets;
    }
}