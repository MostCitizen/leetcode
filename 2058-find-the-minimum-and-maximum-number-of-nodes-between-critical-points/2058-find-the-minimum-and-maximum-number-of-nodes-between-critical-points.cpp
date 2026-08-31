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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v;
        int prev = 0;
        int cur = 0;
        int next = 0;
        int index = 0;
        while(head){
            prev = cur;
            cur = next;
            next = head->val;
            index++;
            if(prev && cur && next){
                if((prev < cur && cur > next) || (prev > cur && cur < next)){
                    v.push_back(index);
                }
            }
            head = head->next;
        }
        if(v.size() <= 1) return {-1, -1};
        int m = INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            m = min(m, v[i+1] - v[i]);
        }
        return {m, v[v.size()-1] - v[0]};
    }
};