/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* cur = head;
        vector<ListNode*> v;
        while(cur){
            v.push_back(cur);
            cur = cur->next;
        }
        int size = v.size();
        int re = k % size;
        if(re == 0) return head;
        v[size-1-re]->next = nullptr;
        v[size-1]->next = head;
        return v[size-re];
    }
};