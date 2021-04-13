// Runtime: 0 ms, faster than 100.00% of Java online submissions for Reverse Linked List.
// Memory Usage: 38.7 MB, less than 64.30% of Java online submissions for Reverse Linked List.

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution
{
    public ListNode reverseList(ListNode head)
    {
        if (head == null)
        {
            return head;
        }

        ListNode curr = head;
        while (curr.next != null)
        {
            ListNode tmp = curr.next.next;
            curr.next.next = head;
            head = curr.next;
            curr.next = tmp;
        }

        return head;
    }
}