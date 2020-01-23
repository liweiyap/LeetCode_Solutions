// Your runtime beats 73.25 % of java submissions.
// Your memory usage beats 87.15 % of java submissions.

 class ListNode
 {
     int val;
     ListNode next;

     ListNode(int x)
     {
         val = x;
     }
 }

class Solution
{
    public ListNode addTwoNumbers(ListNode l1, ListNode l2)
    {
        ListNode sum = new ListNode(l1.val+l2.val);

        ListNode l1_ = l1;
        ListNode l2_ = l2;
        ListNode sum_ = sum;
        while (l1_.next != null && l2_.next != null)
        {
            if (sum_.val >= 10)
            {
                sum_.val -= 10;
                sum_.next = new ListNode(1);
            }

            l1_ = l1_.next;
            l2_ = l2_.next;

            if (sum_.next == null)
            {
                sum_.next = new ListNode(l1_.val+l2_.val);
            }
            else
            {
                sum_.next.val += l1_.val+l2_.val;
            }

            sum_ = sum_.next;
        }

        while (l1_.next != null)
        {
            if (sum_.val >= 10)
            {
                sum_.val -= 10;
                sum_.next = new ListNode(1);
            }

            l1_ = l1_.next;

            if (sum_.next == null)
            {
                sum_.next = new ListNode(l1_.val);
            }
            else
            {
                sum_.next.val += l1_.val;
            }

            sum_ = sum_.next;
        }

        while (l2_.next != null)
        {
            if (sum_.val >= 10)
            {
                sum_.val -= 10;
                sum_.next = new ListNode(1);
            }

            l2_ = l2_.next;

            if (sum_.next == null)
            {
                sum_.next = new ListNode(l2_.val);
            }
            else
            {
                sum_.next.val += l2_.val;
            }

            sum_ = sum_.next;
        }

        if (sum_.val >= 10)
        {
            sum_.val -= 10;
            sum_.next = new ListNode(1);
        }

        return sum;
    }
}