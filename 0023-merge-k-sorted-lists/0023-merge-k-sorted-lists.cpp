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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;
        else if(n == 1) return lists[0];
        vector<ListNode*> v;
        for(int i=0;i<n;i+=2){
            if(i+1 == n) break;
            v.push_back(merge(lists[i], lists[i+1]));
        }
        if(n % 2 == 1){
            v.push_back(lists[n-1]);
        }
        if(v.size() == 1){
            return v[0];
        }else {
            return mergeKLists(v);
        }
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* res = new ListNode();
        ListNode* cur = res;
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1){
            cur->next = l1;
        }else if(l2){
            cur->next = l2;
        }
        return res->next;
    }
};