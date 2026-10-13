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
        if(left == right) return head;
        ListNode* cur = head;
        ListNode* first = nullptr, *last = nullptr, *firstPrev = nullptr;
        int index = 1;
        while(cur){
            if(index < left){
                firstPrev = cur;
                cur = cur->next;
            }else if(index == left){
                last = cur;
                cur = cur->next;
            }else {
                last->next = cur->next;
                first = cur;
                if(firstPrev){
                    first->next = firstPrev->next;
                    firstPrev->next = first;
                }else {
                    first->next = head;
                    head = first;
                }
                if(index == right){
                    break;
                }
                cur = last->next;
            }
            index++;
        }
        return head;
    }
};