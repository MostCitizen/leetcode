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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode node = null;
        ListNode startNode = null, lastNode = null;
        int index = 1;
        ListNode cur = head, nodeCur = node;
        while(cur != null){
            if(index < left) startNode = cur;
            else if(index == left) {
                node = new ListNode(cur.val);
                lastNode = node;
            }
            else if(index > left && index <= right){
                ListNode temp = new ListNode(cur.val);
                temp.next = node;
                node = temp;
            }else if(index == right + 1){
                if(startNode != null)
                    startNode.next = node;
                else head = node;
                lastNode.next = cur;
            }
            index++;
            cur = cur.next;
        }
        if(left == 1 && index == right + 1) return node;
        else if(index == right + 1) {
            startNode.next = node;
            lastNode.next = cur;
        }
        return head;
    }
}