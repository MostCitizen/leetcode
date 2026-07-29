/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode? next;
 *   ListNode([this.val = 0, this.next]);
 * }
 */
class Solution {
  ListNode? addTwoNumbers(ListNode? l1, ListNode? l2) {
    ListNode? res = new ListNode();
    int carry = 0;
    ListNode? cur = res;
    while(l1 != null || l2 != null){
        int sum = 0;
        if(l1 != null){
            sum += l1.val;
            l1 = l1.next;
        }
        if(l2 != null){
            sum += l2.val;
            l2 = l2.next;
        }
        sum += carry;
        ListNode? newNode = new ListNode(sum % 10);
        carry = sum ~/ 10;
        cur!.next = newNode;
        cur = cur.next;
    }
    if(carry != 0){
        ListNode? newNode = new ListNode(1);
        cur!.next = newNode;
        cur = cur.next;
    }
    return res.next;
  }
}