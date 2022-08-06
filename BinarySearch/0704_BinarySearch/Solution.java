// Runtime: 0 ms, faster than 100.00% of Java online submissions for Binary Search.
// Memory Usage: 54.6 MB, less than 32.85% of Java online submissions for Binary Search.

class Solution {
    public int search(int[] nums, int target) {
        int l = 0;
        int r = nums.length - 1;
        while (l <= r) {
            final int m = (l + r) / 2;
            if (nums[m] < target) {
                l = m + 1;
            }
            else if (nums[m] > target) {
                r = m - 1;
            }
            else {
                return m;
            }
        }
        return -1;
    }
}