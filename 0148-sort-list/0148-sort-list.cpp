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
    ListNode* sortList(ListNode* head) {
        vector<int> temp;
        while(head){
            temp.push_back(head->val);
            head = head->next;
        }
        head = new ListNode();
        ListNode* cur = head;

        sort(temp.begin(), temp.end());
        for(int i=0;i<temp.size();i++){
            cur->next = new ListNode(temp[i]);
            cur = cur->next;
        }
        return head->next;
    }
};