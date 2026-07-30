/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode? next;
 *   ListNode([this.val = 0, this.next]);
 * }
 */
class Solution {
  ListNode? mergeTwoLists(ListNode? list1, ListNode? list2) {
    if(list1 == null) return list2;
    else if(list2 == null) return list1;
    ListNode? res = new ListNode();
    ListNode? cur = res;
    while(list1 != null || list2 != null){
        if(list2 == null || (list1 != null && list1.val <= list2.val)){
            cur!.next = new ListNode(list1!.val);
            list1 = list1.next;
        } else {
            cur!.next = new ListNode(list2.val);
            list2 = list2.next;
        }
        cur = cur.next;
    }
    return res.next;
  }
}