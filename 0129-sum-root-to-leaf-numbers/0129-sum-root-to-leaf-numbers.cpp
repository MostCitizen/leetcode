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
        vector<int> v;
        roop(root, v, 0);
        int sum =0;
        for(int i=0;i<v.size();i++){
            sum += v[i];
        }
        return sum;
    }

    void roop(TreeNode* root, vector<int>& v, int sum){
        if(!root) return;
        sum = sum * 10 + root->val;
        if(root && !root->left && !root->right){
            v.push_back(sum);
            return;
        }
        roop(root->left, v, sum);
        roop(root->right, v, sum);
    }
};