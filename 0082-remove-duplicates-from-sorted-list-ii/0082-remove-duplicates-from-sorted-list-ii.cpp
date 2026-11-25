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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* cur = head, *prev = nullptr, *next = head->next;
        while(next && cur){
            if(cur->val == next->val){
                ListNode* temp = cur;
                while(temp && temp->val == next->val){
                    temp = temp->next;
                }
                if(cur == head){
                    head = temp;
                    prev = nullptr;
                }else {
                    prev->next = temp;
                }
                cur = temp;
            }else {
                prev = cur;
                cur = cur->next;
            }
            if(cur)
                next = cur->next;
        }
        return head;
    }
};