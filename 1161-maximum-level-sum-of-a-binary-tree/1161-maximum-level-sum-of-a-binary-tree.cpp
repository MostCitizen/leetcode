/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void sum(TreeNode* node, int level, unordered_map<int, int>& mp){
        if(!node) return;
        mp[level] += node->val;
        sum(node->left, level+1, mp);
        sum(node->right, level+1, mp);
    }
    int maxLevelSum(TreeNode* root) {
        unordered_map<int, int> mp;
        sum(root, 0, mp);
        int m = -INT_MAX;
        int res = 0;
        for(int i=0;i<mp.size();i++){
            if(m < mp[i]){
                res = i+1;
                m = mp[i];
            }
        }
        return res;
    }
};