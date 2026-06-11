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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> temp;
        while(list1 != NULL || list2 != NULL){
            if(list1 != NULL){
                temp.push_back(list1->val);
                list1 = list1->next;
            }
            if(list2 != NULL){
                temp.push_back(list2->val);
                list2 = list2->next;
            }
        }
        if(temp.size() == 0) return list1;
        sort(temp.begin(), temp.end());
        ListNode* result = new ListNode(temp[0]);
        ListNode* tempNode = result;
        for(int i=1;i<temp.size();i++){
            tempNode->next = new ListNode(temp[i]);
            tempNode = tempNode->next;
        }
        return result;
    }
};