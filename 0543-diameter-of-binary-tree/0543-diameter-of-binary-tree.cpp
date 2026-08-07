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
    vector<int> v;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
            res = max(res, find(cur->left, 0) + find(cur->right, 0));
        }

        return res;
    }

    int find(TreeNode* node, int length){
        if(!node) {
            return length;
        }
        return max(find(node->left, length+1), find(node->right, length+1));
    }
};