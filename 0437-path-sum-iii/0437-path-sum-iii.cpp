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
    long long count = 0;
    void find(TreeNode* root, long long targetSum, long long sum){
        if(!root){
            return;
        }
        sum += root->val;
        if(targetSum == sum){
            count++;
        }
        find(root->left, targetSum, sum); 
        find(root->right, targetSum, sum);
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            find(cur, targetSum, 0);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return count;
    }
};