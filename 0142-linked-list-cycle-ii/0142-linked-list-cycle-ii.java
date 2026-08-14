/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null || head.next == null) return null;
        Map<ListNode, Integer> mp = new HashMap<>();
        ListNode cur = head;
        while(cur != null){
            if(mp.getOrDefault(cur, 0) > 0) return cur;
            mp.put(cur, 1);
            cur = cur.next;
        }
        return null;
    }
}