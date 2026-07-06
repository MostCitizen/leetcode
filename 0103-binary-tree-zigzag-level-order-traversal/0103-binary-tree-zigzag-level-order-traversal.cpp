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
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);

        bool isZigzag = false;
        while(!q.empty()){
            int s = q.size();
            vector<int> v;
            for(int i=0;i<s;i++){
                TreeNode* front = q.front();
                q.pop();
                v.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            if(isZigzag) reverse(v.begin(), v.end());
            isZigzag = !isZigzag;
            res.push_back(v);
        }
        return res;
    }
};