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
        if(head == null || head.next == null) return head;
        ListNode slowPrev = null;
        ListNode slow = head;
        ListNode fast = head.next;
        while(fast != null){
            ListNode temp = slow;
            slow.next = fast.next;
            fast.next = slow;
            if(slowPrev != null) slowPrev.next = fast;
            else head = fast;
            slowPrev = slow;
            slow = slow.next;
            if(slow == null) break;
            fast = slow.next;
        }
        return head;
    }
}