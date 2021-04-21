// Runtime: 80 ms, faster than 87.67% of C++ online submissions for LRU Cache.
// Memory Usage: 39.8 MB, less than 85.34% of C++ online submissions for LRU Cache.

#include <list>
#include <unordered_map>

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        _capacity = capacity;
    }
    
    int get(int key)
    {
        if (_hashMap.find(key) == _hashMap.end())
        {
            return -1;
        }
        
        // moves only the element pointed by _hashMap[key] from _list into _list.begin()
        _list.splice(_list.begin(), _list, _hashMap[key]);
        
        return _hashMap[key]->second;
    }
    
    void put(int key, int value)
    {
        if (get(key) != -1)
        {
            _hashMap[key]->second = value;
            return;
        }
        
        if (_capacity == _hashMap.size())
        {
            int lastKey = _list.back().first;
            _list.pop_back();
            _hashMap.erase(lastKey);
        }
        
        _list.emplace_front(std::pair(key,value));
        _hashMap[key] = _list.begin();
    }
    
private:
    int _capacity;
    std::list<std::pair<int,int>> _list;
    std::unordered_map<int,std::list<std::pair<int,int>>::iterator> _hashMap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
