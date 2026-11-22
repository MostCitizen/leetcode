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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        queue<ListNode*> q;
        ListNode* cur = head;
        while(cur){
            if(q.size() < n + 1){
                q.push(cur);
            }else {
                q.pop();
                q.push(cur);
            }
            cur = cur->next;
        }
        if(q.size() == n) return head->next;
        else {
            ListNode* ln = q.front();
            ln->next = ln->next->next;
        }
        return head;
    }
};