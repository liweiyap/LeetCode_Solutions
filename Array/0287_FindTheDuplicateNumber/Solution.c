// Runtime: 4 ms, faster than 99.64% of C online submissions for Find the Duplicate Number.
// Memory Usage: 6.5 MB, less than 100.00% of C online submissions for Find the Duplicate Number.

int findDuplicate(int* nums, int numsSize)
{
    int* slow = nums;
    int* fast = nums;
    while (true)
    {
        slow = nums + (*slow);
        fast = nums + (*fast);
        fast = nums + (*fast);
        if (slow == fast)
        {
            break;
        }
    }
    
    slow = nums;
    while (*slow != *fast)
    {
        slow = nums + (*slow);
        fast = nums + (*fast);
    }
    return *slow;
}
