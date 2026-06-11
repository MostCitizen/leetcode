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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> v;
        ListNode* result = new ListNode();
        ListNode* cur = result;
        while(head){
            v.push_back(head->val);
            cur->next = new ListNode(head->val);
            head = head->next;
            cur = cur->next;
        }
        cur = result;
        cur = cur->next;
        for(int i=0;i<v.size()/k;i++){
            for(int j=k-1;j>=0;j--){
                cur->val = v[i*k+j];
                cur = cur->next;
            }
        }
        return result->next;
    }
};