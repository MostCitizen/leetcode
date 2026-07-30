/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        Node* res = new Node(0);
        unordered_map<Node*, Node*> map;
        Node* cur = head;
        Node* curRes = res;
        int count = 0;
        while(cur){
            curRes->next = new Node(cur->val);
            curRes = curRes->next;
            map[cur] = curRes;
            cur = cur->next;
            count++;
        }
        cur = head;
        for(int i=0;i<count;i++){
            Node* temp = cur;
            map[temp]->random = map[temp->random];
            cur = cur->next;
        }
        return res->next;
    }
};