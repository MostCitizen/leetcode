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
    int sumNumbers(TreeNode* root) {
        return sumNode(root, 0);
    }

    int sumNode(TreeNode* node, int sum){
        if(!node) return sum;
        sum = sum * 10 + node->val;
        int left = 0, right = 0;
        if(node->left){
            left = sumNode(node->left, sum);
        }
        if(node->right){
            right = sumNode(node->right, sum);
        }
        return left + right == 0 ? sum : left + right;
    }
};