// Runtime: 4 ms, faster than 94.15% of C++ online submissions for Remove Nth Node From End of List.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Remove Nth Node From End of List.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* first = head;
        ListNode* last = head;
        
        for (int counter = 0; counter < n; ++counter)
        {
            if (!last->next && counter == n-1)  // edge case where we have to remove the head
            {
                head = head->next;
                return head;
            }
            
            last = last->next;
        }
        
        while (last->next)
        {
            first = first->next;
            last = last->next;
        }
        
        ListNode* removed = first->next;
        first->next = removed->next;
        removed = nullptr;
        
        return head;
    }
};
