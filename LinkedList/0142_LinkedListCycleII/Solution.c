// Runtime: 8 ms, faster than 59.66% of C online submissions for Linked List Cycle II.
// Memory Usage: 6.8 MB, less than 100.00% of C online submissions for Linked List Cycle II.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head)
{
    if (!head || !head->next || !head->next->next)
    {
        return NULL;
    }
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (slow->next && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    
    if (slow != fast)
    {
        return NULL;
    }
    
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
