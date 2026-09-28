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
        ListNode* cur = head;
        ListNode* start = head;
        ListNode* prev = nullptr;
        int count = 1;
        while(cur->next){
            count++;
            cur = cur->next;
            if(count == k){
                count = 1;
                change(start, cur, prev, head);
                if(start == head) {
                    head = cur;
                }
                if(start->next) {
                    prev = start;
                    start = start->next;
                    cur = start;
                }
            }
        }
        return head;
    }
    void change(ListNode* first, ListNode* last, ListNode* prev, ListNode* head){
        if(first == last || !first || !last) return;
        ListNode* target = first;
        while(target->next && target->next != last){
            target = target->next;
        }
        if(target != last && first != target) {
            ListNode* temp = first->next;
            change(temp, target, first, head);
            first->next = !last->next ? nullptr : last->next;
            last->next = target;
            temp->next = first;
        }else {
            first->next = last->next;
            last->next = first;
        }
        if(prev) {
            prev->next = last;
        }
    }
};