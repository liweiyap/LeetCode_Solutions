// Runtime: 8 ms, faster than 92.29% of Java online submissions for Top K Frequent Elements.
// Memory Usage: 41.8 MB, less than 31.15% of Java online submissions for Top K Frequent Elements.

import java.util.*;
import java.util.Map.*;

class Solution
{
    // reduces time significantly
    // https://stackoverflow.com/questions/81346/most-efficient-way-to-increment-a-map-value-in-java
    private class MutableInteger
    {
        private int value = 1;  // note that we start at 1 since we're counting

        public void increment()
        {
            ++value;
        }

        public Integer get()
        {
            return value;
        }
    };

    public int[] topKFrequent(int[] nums, int k)
    {
        /* build hash map */

        HashMap<Integer,MutableInteger> hash = new HashMap<Integer,MutableInteger>();
        for (int idx = 0; idx < nums.length; ++idx)
        {
            MutableInteger count = hash.get(nums[idx]);
            if (count == null)
            {
                hash.put(nums[idx], new MutableInteger());
            }
            else
            {
                count.increment();
            }
        }

        /* sort hash map */

        List<Entry<Integer,MutableInteger>> list = new LinkedList<Entry<Integer, MutableInteger>>(hash.entrySet());
        Collections.sort(list, new Comparator<Entry<Integer, MutableInteger>>()
        {
            public int compare(Entry<Integer,MutableInteger> o1, Entry<Integer,MutableInteger> o2)
            {
                return o2.getValue().get().compareTo(o1.getValue().get());
            }
        });

        /* output k most frequent keys */

        int[] output = new int[k];
        int idx = 0;
        for (Entry<Integer,MutableInteger> entry : list)
        {
            output[idx++] = entry.getKey();

            if (idx == k)
            {
                break;
            }
        }

        return output;
    }
}