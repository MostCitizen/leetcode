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
    ListNode* partition(ListNode* head, int x) {
        ListNode* leftNode = new ListNode(), *rightNode = new ListNode();
        ListNode* cur = head;
        ListNode* curLeft = leftNode, *curRight = rightNode;
        while(cur){
            if(cur->val < x){
                curLeft->next = cur;
                curLeft = curLeft->next;
                cur = cur->next;
            }else {
                ListNode* temp = cur->next;
                curRight->next = cur;
                curRight = curRight->next;
                curRight->next = nullptr;
                cur = temp;
            }
        }
        if(curLeft) {
            curLeft->next = rightNode->next;
            return leftNode->next;
        }else {
            return rightNode->next;
        }
    }
};