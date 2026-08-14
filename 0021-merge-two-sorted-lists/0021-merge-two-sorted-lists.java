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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode res = new ListNode();
        ListNode cur = res;
        while(list1 != null || list2 != null){
            if(list1 != null && list2 != null){
                if(list1.val < list2.val){
                    cur.next = new ListNode(list1.val);
                    list1 = list1.next;
                }else{
                    cur.next = new ListNode(list2.val);
                    list2 = list2.next;
                }
            }else if(list1 != null){
                cur.next = list1;
                break;
            }else {
                cur.next = list2;
                break;
            }
            cur = cur.next;
        }
        return res.next;
    }
}