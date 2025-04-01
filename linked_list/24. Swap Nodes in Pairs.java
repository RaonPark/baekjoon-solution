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
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode temp = head;

        if(temp == null)
            return head;

        while(temp.next != null) {
            ListNode first = temp;
            ListNode second = temp.next;

            int val = first.val;
            first.val = second.val;
            second.val = val;

            if(temp.next.next == null)
                break;
            temp = temp.next.next;
        }

        return head;
    }
}
