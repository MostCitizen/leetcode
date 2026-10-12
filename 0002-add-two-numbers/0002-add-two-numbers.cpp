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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* prev = l1;
        int carry = 0;
        while(l1 && l2){
            int val = l1->val + l2->val + carry;
            carry = val / 10;
            val %= 10;
            l1->val = val;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l2){
            prev->next = l2;
            l1 = l2;
        }
        while(carry){
            if(!l1){
                prev->next = new ListNode(1);
                break;
            }
            int val = l1->val + carry;
            cout << val % 10 << endl;
            carry = val / 10;
            l1->val = val % 10; 
            prev = l1;
            l1 = l1->next;
        }
        return head;
    }
};