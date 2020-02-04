// Runtime: 148 ms, faster than 94.21% of C++ online submissions for Find Median from Data Stream.
// Memory Usage: 42.4 MB, less than 100.00% of C++ online submissions for Find Median from Data Stream.

#include <vector>
#include <queue>
#include <cassert>

class MedianFinder
{
public:
    MedianFinder(){}
    
    void addNum(int num)
    {
        if (smallVals.empty() || num <= smallVals.top())
        {
            smallVals.push(num);
        }
        else
        {
            largeVals.push(num);
        }
        
        balanceHeaps();
    }
    
    double findMedian()
    {
        if (smallVals.size() == 0)
        {
            assert(largeVals.size() == 1);
            return largeVals.top();
        }
        if (largeVals.size() == 0)
        {
            assert(smallVals.size() == 1);
            return smallVals.top();
        }
        
        int count = smallVals.size() + largeVals.size();
        
        if (count % 2 == 1)
        {
            return (smallVals.size() > largeVals.size()) ? static_cast<double>(smallVals.top()) : static_cast<double>(largeVals.top());
        }
        else
        {
            assert(smallVals.size() == largeVals.size());
            return 0.5 * (smallVals.top() + largeVals.top());
        }
    }
    
    void balanceHeaps()
    {
        while (!smallVals.empty() && largeVals.size() < smallVals.size() - 1)
        {
            int num = smallVals.top();
            smallVals.pop();
            largeVals.push(num);
        }
        
        while (!largeVals.empty() && smallVals.size() < largeVals.size() - 1)
        {
            int num = largeVals.top();
            largeVals.pop();
            smallVals.push(num);
        }
    }
    
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> largeVals;  // min-heap
    std::priority_queue<int> smallVals;                                       // max-heap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
