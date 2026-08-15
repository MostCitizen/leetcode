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
    public ListNode reverseList(ListNode head) {
        if(head == null) return head;
        head = reverse(null, head);
        return head;
    }
    private ListNode reverse(ListNode prev, ListNode next){
        if(next == null) return prev;
        ListNode temp = reverse(next, next.next);
        next.next = prev;
        return temp;
    }
}