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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> temp;
        ListNode* result = new ListNode();
        ListNode* tempNode = result;
        while(head){
            temp.push_back(head->val);
            tempNode->next = new ListNode(head->val);
            tempNode = tempNode->next;
            head = head->next;
        }
        tempNode = result;
        for(int i=0;i<left;i++){
            tempNode = tempNode->next;
        }
        for(int i=right;i>=left;i--){
            tempNode->val = temp[i-1];
            tempNode = tempNode->next;
        }
        return result->next;
    }
};