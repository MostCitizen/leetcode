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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != nullptr) slow = slow->next;

        ListNode* right = reverse(slow);
        ListNode* left = head;

        while(left && right){
            if(left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr, *cur = head;
        while(cur){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};