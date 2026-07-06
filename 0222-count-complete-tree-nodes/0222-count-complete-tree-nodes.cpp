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
private:
    int leftHeight(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root->left;
        }
        return height;
    }
    int rightHeight(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root->right;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lH = leftHeight(root);
        int rH = rightHeight(root);
        if(lH == rH) return (1 << rH) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};