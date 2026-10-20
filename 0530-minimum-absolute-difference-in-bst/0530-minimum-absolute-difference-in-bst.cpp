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
    int getMinimumDifference(TreeNode* root) {
        if(!root) return INT_MAX;
        int m = INT_MAX;
        int dif = root->val;
        TreeNode* node = root->left;
        if(node){
            while(node->right){
                node = node->right;
            }
            m = min(m, abs(dif - node->val));
        }
        node = root->right;
        if(node){
            while(node->left){
                node = node->left;
            }
            m = min(m, abs(dif - node->val));
        }
        m = min({m, getMinimumDifference(root->left),getMinimumDifference(root->right)});
        return m;
    }
};