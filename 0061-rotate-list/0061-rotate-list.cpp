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
        vector<int> v;
        while(cur){
            v.push_back(cur->val);
            cur = cur->next;
        }
        ListNode* res = new ListNode();
        cur = res;
        int n = v.size();
        k = k % n;
        if(k == 0) return head;
        for(int i=0;i<n;i++){
            cur->next = new ListNode(v[(n - k + i)%n]);
            cur = cur->next;
        }
        return res->next;
    }
};