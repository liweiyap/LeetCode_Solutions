// Runtime: 4 ms, faster than 97.95% of C online submissions for Linked List Cycle.
// Memory Usage: 6.8 MB, less than 100.00% of C online submissions for Linked List Cycle.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{
    if (!head || !head->next)
    {
        return false;
    }
    
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while (slow->next && fast->next && fast->next->next && slow != fast)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return (slow == fast);
}
