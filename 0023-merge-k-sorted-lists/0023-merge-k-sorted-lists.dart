/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode? next;
 *   ListNode([this.val = 0, this.next]);
 * }
 */
class Solution {
  ListNode? mergeKLists(List<ListNode?> lists) {
    if(lists.length == 0) return null;
    ListNode? res = lists[0];
    for(int i=1;i<lists.length;i++){
        res = merge(res, lists[i]);
    }
    return res;
  }
  ListNode? merge(ListNode? list1, ListNode? list2){
    if(list2 == null) return list1;
    ListNode? res = new ListNode();
    ListNode? cur = res;
    while(list1 != null || list2 != null){
        if(list2 == null || (list1 != null && list1.val <= list2.val)){
            cur!.next = list1;
            list1 = list1!.next;
        }else {
            cur!.next = list2;
            list2 = list2.next;
        }
        cur = cur.next;
    }
    return res.next;
  }
}