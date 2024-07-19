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
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return res;
    }
    int res = 0;
    int dfs(TreeNode* root)
    {
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int val = 1;
        if(left && root->val == root->left->val - 1)
        {
            val = left + 1;
        }
        if(right && root->val == root->right->val - 1)
        {
            val = max(val, right + 1);
        }
        res = max(res, val);
        return val;
    }
};