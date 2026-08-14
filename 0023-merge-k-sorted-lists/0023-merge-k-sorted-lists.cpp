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
        if(lists.size() == 0) return nullptr;
        else if(lists.size() == 1) return lists[0];
        vector<ListNode*> temp;
        for(int i=0;i<lists.size()-1;i+=2){
            temp.push_back(mergerTow(lists[i], lists[i+1]));
        }
        if(lists.size() % 2 == 1){
            temp.push_back(lists[lists.size()-1]);
        }
        return mergeKLists(temp);
    }

    ListNode* mergerTow(ListNode* node1, ListNode* node2){
        ListNode* res = new ListNode();
        ListNode* cur = res;
        while(node1 && node2){
            if(node1->val < node2->val){
                cur->next = new ListNode(node1->val);
                node1 = node1->next;
            }else {
                cur->next = new ListNode(node2->val);
                node2 = node2->next;
            }
            cur = cur->next;
        }
        cur->next = node1 ? node1 : node2;
        return res->next;
    }
};