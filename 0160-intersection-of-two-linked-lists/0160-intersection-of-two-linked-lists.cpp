/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> v;
        while(headA || headB){
            if(headA == headB) return headA;
            if(headA){
                if(find(v.begin(), v.end(), headA) != v.end()){
                    return headA;
                }
                v.push_back(headA);
                headA = headA->next;
            }
            if(headB){
                if(find(v.begin(), v.end(), headB) != v.end()){
                    return headB;
                }
                v.push_back(headB);
                headB = headB->next;
            }
        }
        return nullptr;
    }
};