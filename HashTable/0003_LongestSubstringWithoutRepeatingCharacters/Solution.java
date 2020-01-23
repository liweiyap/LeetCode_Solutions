// Your runtime beats 82.31 % of java submissions.
// Your memory usage beats 99.76 % of java submissions.

import java.util.HashMap;

class Solution
{
    public int lengthOfLongestSubstring(String s)
    {
        if (s == null)
        {
            return 0;
        }

        HashMap<Character, Integer> dict = new HashMap<Character, Integer>();
        int maxLength = 0;
        int currLength = 0;
        int left = 0;
        for (int idx = 0; idx < s.length(); ++idx)
        {
            Character letter = s.charAt(idx);
            if (dict.containsKey(letter) && dict.get(letter) >= left)
            {
                currLength = idx - left;
                left = dict.get(letter) + 1;
                dict.put(letter, idx);
                maxLength = (currLength > maxLength) ? currLength : maxLength;
            }
            else
            {
                dict.put(letter, idx);
            }
        }
        maxLength = (s.length() - left > maxLength) ? s.length() - left : maxLength;
        return maxLength;
    }
}