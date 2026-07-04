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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return temp(root, 0, targetSum);
    }

    bool temp(TreeNode* root, int sum, int targetSum){
        if(!root) return false;
        sum += root->val;
        if(root && sum == targetSum && !root->left && !root->right) return true;

        return temp(root->left, sum, targetSum) ||
            temp(root->right, sum, targetSum);
    }
};