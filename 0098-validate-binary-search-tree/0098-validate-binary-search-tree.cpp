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
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
    bool isValid(TreeNode* node, long long minV, long long maxV){
        if(!node) return true;
        else if(node->val <= minV || node->val >= maxV) return false;
        return isValid(node->left, minV, node->val) &&
            isValid(node->right, node->val, maxV); 
    }
};