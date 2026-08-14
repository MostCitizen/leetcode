/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head == null) return head;
        Map<Node, Node> mp = new HashMap<>();
        Node res = new Node(0);
        Node cur = res;
        Node temp = head;
        while(temp != null){
            cur.next = new Node(temp.val);
            cur = cur.next;
            mp.put(temp, cur);
            temp = temp.next;
        }
        temp = head;
        cur = res.next;
        while(temp != null){
            cur.random = mp.get(temp.random);
            temp = temp.next;
            cur = cur.next;
        }
        return res.next;
    }
}