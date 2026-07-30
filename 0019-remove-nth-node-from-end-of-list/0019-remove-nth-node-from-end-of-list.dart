/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode? next;
 *   ListNode([this.val = 0, this.next]);
 * }
 */
class Solution {
  ListNode? removeNthFromEnd(ListNode? head, int n) {
    if(head == null) return head;
    List<ListNode?> list = [];
    ListNode? cur = head;
    while(cur != null){
        list.add(cur);
        cur = cur.next;
    }
    if(list.length - n == 0){
        return head.next;
    }
    list[list.length-n-1]!.next = list[list.length-n]!.next;
    return head;
  }
}