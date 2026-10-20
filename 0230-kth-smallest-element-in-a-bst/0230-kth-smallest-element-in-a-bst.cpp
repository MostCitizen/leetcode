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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return find(root, k, count);
    }
    int find(TreeNode* root, int k, int& count){
        if(!root) return -1;
        int left = find(root->left, k, count);
        count++;
        if(count == k) return root->val;
        int right = find(root->right,k, count);
        if(left != -1) return left;
        else if(right != -1) return right;
        return -1;
    }
};