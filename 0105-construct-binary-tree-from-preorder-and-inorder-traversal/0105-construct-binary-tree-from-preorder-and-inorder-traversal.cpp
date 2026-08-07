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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        queue<int> q(preorder.begin(), preorder.end());
        return build(q, inorder);
    }
    TreeNode* build(queue<int>& q, vector<int> inorder){
        if(inorder.empty()) return nullptr;
        int val = q.front();
        q.pop();
        auto it = find(inorder.begin(), inorder.end(), val);
        int index = it - inorder.begin();

        TreeNode* node = new TreeNode(val);
        vector<int> left(inorder.begin(), inorder.begin() + index);
        vector<int> right(inorder.begin() + index + 1, inorder.end());

        node->left = build(q, left);
        node->right = build(q, right);
        return node;
    }
};