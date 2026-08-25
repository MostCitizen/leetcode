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
        ListNode* cur = head;
        ListNode* res = head;
        set<int> removeSet;
        while(cur->next){
            if(cur->val == cur->next->val) {
                removeSet.insert(cur->val);
                cur = cur->next;
            }
            else if(removeSet.count(cur->val) == 0){
                ListNode* temp = cur->next;
                cur->next = nullptr;
                if(res != cur){
                    res->next = cur;
                    res = res->next;
                }
                cur = temp;
            }else {
                cur = cur->next;
            }
        }
        if(removeSet.count(cur->val) == 0 && res != cur){
            res->next = cur;
            res = res->next;
        }
        while(head && removeSet.count(head->val) > 0){
            head = head->next;
        }
        return head;
    }
};