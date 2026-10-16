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
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* cur = root;
        while(cur){
            if(cur->left){
                TreeNode* temp = cur->right;
                TreeNode* right = cur->left;
                cur->right = cur->left;
                cur->left = nullptr;
                while(right->right){
                    right = right->right;
                }
                right->right = temp;
            }
            cur = cur->right;
        }
        return;
    }
};