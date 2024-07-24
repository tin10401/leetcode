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
    int res = 0;
    array<int, 4> dfs(TreeNode* root)
    {
        if(!root) return {0, true, INT_MIN, INT_MAX};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        array<int, 4> curr = {
            left[0] + right[0] + root->val, 
            left[1] && right[1],
            max({left[2], right[2], root->val}), 
            min({left[3], right[3], root->val})};
        if(root->val <= left[2] || root->val >= right[3]) curr[1] = false;
        
        if(curr[1]) res = max(res, curr[0]);
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return res; 
    }
};