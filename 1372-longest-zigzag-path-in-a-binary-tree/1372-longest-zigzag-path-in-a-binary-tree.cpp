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
    int find(TreeNode* node, bool isLeft, int count){
        if(!node) return count;
        else if(isLeft){
            if(!node->right)
                return count;
            else
                return find(node->right, !isLeft, count+1);
        } 
        else{
            if(!node->left)
                return count;
            else
                return find(node->left, !isLeft, count+1);
        }
        
    }
    int longestZigZag(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return 0;
        int m = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            m = max({m, find(cur, false, 0), find(cur, true, 0)});
            if(cur->left){
                q.push(cur->left);
            }
            if(cur->right){
                q.push(cur->right);
            }
        }
        return m;
    }
};