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
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* cur = q.front();
                q.pop();
                int count = 0;
                int sum = 0;
                find(cur, count, sum);
                if(cur->val == sum / count) res++;

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return res;
    }

    void find(TreeNode* node, int& count, int& sum){
        if(!node) return;
        sum += node->val;
        count++;
        find(node->left, count, sum);
        find(node->right, count, sum);
        return;

    }
};