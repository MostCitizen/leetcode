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
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }

    pair<int, int> dfs(TreeNode* node, int& res){
        if(!node) return {0, 0};

        pair<int, int> left = dfs(node->left, res);
        pair<int, int> right = dfs(node->right, res);
        
        int sum = left.first + right.first + node->val;
        int count = left.second + right.second + 1;
        
        if(node->val == sum / count) res++;

        return {sum, count};
    }
};