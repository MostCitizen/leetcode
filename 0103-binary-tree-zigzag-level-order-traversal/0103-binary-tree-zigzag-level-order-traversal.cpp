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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        bool isZigzag = false;
        while(!q.empty()){
            int size = q.size();
            isZigzag = !isZigzag;
            vector<int> v;
            for(int i=0;i<size;i++){
                TreeNode* cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            if(!isZigzag) reverse(v.begin(), v.end());
            res.push_back(v);
        }
        return res;
    }
};