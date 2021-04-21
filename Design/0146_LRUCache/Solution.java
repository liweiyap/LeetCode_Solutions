/* Without LinkedHashMap */

// Runtime: 226 ms, faster than 5.03% of Java online submissions for LRU Cache.
// Memory Usage: 46.7 MB, less than 97.43% of Java online submissions for LRU Cache.

class LRUCache
{
    public LRUCache(int capacity)
    {
        _capacity = capacity;
    }

    public int get(int key)
    {
        if (!_hashMap.containsKey(key))
        {
            return -1;
        }

        Iterator _keyLinkedListIt = _keyLinkedList.iterator();
        while (_keyLinkedListIt.hasNext())
        {
            int currKey = (int) _keyLinkedListIt.next();

            if (currKey == key)
            {
                _keyLinkedListIt.remove();
                _keyLinkedList.addLast(key);
                break;
            }
        }

        return (int) _hashMap.get(key);
    }

    public void put(int key, int value)
    {
        Iterator _keyLinkedListIt = _keyLinkedList.iterator();
        while (_keyLinkedListIt.hasNext())
        {
            int currKey = (int) _keyLinkedListIt.next();

            if (currKey == key)
            {
                _keyLinkedListIt.remove();
                _hashMap.remove(key);
                break;
            }
        }

        if (_capacity == _keyLinkedList.size())
        {
            int firstKey = (int) _keyLinkedList.iterator().next();
            _keyLinkedList.removeFirst();
            _hashMap.remove(firstKey);
        }

        _keyLinkedList.addLast(key);
        _hashMap.put(key, value);
    }

    private int _capacity;
    private LinkedList _keyLinkedList = new LinkedList<Integer>();
    private HashMap _hashMap = new HashMap<Integer,Integer>();
}

/* Long version of LinkedHashMap */

// Runtime: 15 ms, faster than 30.47% of Java online submissions for LRU Cache.
// Memory Usage: 46.6 MB, less than 97.39% of Java online submissions for LRU Cache.

// class LRUCache
// {
//     public LRUCache(int capacity)
//     {
//         _capacity = capacity;
//         _linkedHashMap = new LinkedHashMap<Integer,Integer>(capacity);
//     }

//     public int get(int key)
//     {
//         if (!_linkedHashMap.containsKey(key))
//         {
//             return -1;
//         }

//         Object value = _linkedHashMap.get(key);
//         _linkedHashMap.remove(key);      // remove ...
//         _linkedHashMap.put(key, value);  // and add back

//         return (int)value;
//     }

//     public void put(int key, int value)
//     {
//         if (get(key) != -1)
//         {
//             _linkedHashMap.remove(key);
//         }

//         if (_linkedHashMap.size() == _capacity)
//         {
//             Object firstKey = _linkedHashMap.keySet().iterator().next();
//             _linkedHashMap.remove(firstKey);
//         }

//         _linkedHashMap.put(key, value);
//     }

//     private int _capacity;
//     private LinkedHashMap _linkedHashMap;
// }

/* Short version of LinkedHashMap */

// Runtime: 18 ms, faster than 20.61% of Java online submissions for LRU Cache.
// Memory Usage: 57.1 MB, less than 5.02% of Java online submissions for LRU Cache.

// class LRUCache
// {
//     public LRUCache(int capacity)
//     {
//         _linkedHashMap = new LinkedHashMap<Integer,Integer>(capacity, 0.75F, true)
//         {
//             protected boolean removeEldestEntry(Map.Entry<Integer,Integer> eldest)
//             {
// 				return size() > capacity;
// 			}
// 		};
//     }

//     public int get(int key)
//     {
//         return (int) _linkedHashMap.getOrDefault(key, -1);
//     }

//     public void put(int key, int value)
//     {
//         _linkedHashMap.put(key, value);
//     }

//     private LinkedHashMap _linkedHashMap;
// }


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */