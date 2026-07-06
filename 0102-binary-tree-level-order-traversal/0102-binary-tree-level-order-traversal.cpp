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
    void temp(TreeNode* node, unordered_map<int, vector<int>>& mp, int depth){
        if(!node) return;
        mp[depth].push_back(node->val);
        temp(node->left, mp, depth+1);
        temp(node->right, mp, depth+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        unordered_map<int, vector<int>> mp;
        temp(root, mp, 0);
        for(int i=0;i<mp.size();i++){
            res.push_back(mp[i]);
        }
        return res;
    }
};