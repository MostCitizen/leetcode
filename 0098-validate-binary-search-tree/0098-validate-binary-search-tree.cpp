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
    bool isValid(TreeNode* node, long minV, long maxV){
        if(!node) return true;
        if(node->val <= minV || node->val >= maxV) return false;
        return isValid(node->left, minV, node->val) && isValid(node->right, node->val, maxV);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, -LONG_MAX, LONG_MAX);
    }
};