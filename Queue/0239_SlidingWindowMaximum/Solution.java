// Runtime: 9 ms, faster than 85.72% of Java online submissions for Sliding Window Maximum.
// Memory Usage: 47.6 MB, less than 6.25% of Java online submissions for Sliding Window Maximum.

import java.util.Deque;
import java.util.LinkedList;

class Solution
{
    public int[] maxSlidingWindow(int[] nums, int k)
    {
        if (nums.length == 0)
        {
            return nums;
        }

        int[] windows = new int[nums.length - k + 1];
        Deque<Integer> queue = new LinkedList<>();  // double-ended queue to store index of integers in nums array in descending order (from first to last)

        for (int idx = 0; idx < k; ++idx)
        {
            while (!queue.isEmpty() && nums[queue.peekLast()] < nums[idx])
            {
                queue.removeLast();
            }
            queue.addLast(idx);
        }
        windows[0] = nums[queue.peekFirst()];

        for (int idx = k; idx < nums.length; ++idx)
        {
            while (!queue.isEmpty() && queue.peekFirst() < idx-k+1)  // queue can only have a maximum of k entries
            {
                queue.removeFirst();
            }
            while (!queue.isEmpty() && nums[queue.peekLast()] < nums[idx])
            {
                queue.removeLast();
            }
            queue.addLast(idx);
            windows[idx-k+1] = nums[queue.peekFirst()];
        }
        return windows;
    }
}