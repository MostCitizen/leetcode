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
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(!cur) continue;
            v.push_back(cur->val);
            q.push(cur->left);
            q.push(cur->right);
        }
        sort(v.begin(), v.end());
        int m = INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            m = min(m, abs(v[i] - v[i+1]));
        }
        return m;
    }
};