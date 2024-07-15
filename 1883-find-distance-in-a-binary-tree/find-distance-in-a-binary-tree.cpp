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
    int findDistance(TreeNode* root, int p, int q) {
        dfs(root, p, q);
        return res;
    }
    int res = 0;
    int dfs(TreeNode* root, int p, int q)
    {
        if(!root || res) return -1;
        int left = dfs(root->left, p, q);
        int right = dfs(root->right, p, q);
        if(root->val == q || root->val == p)
        {
            if(left < 0 && right < 0) return 0;
            res = left >= 0 ? left + 1 : right + 1;
            return -1;
        }
        if(left >= 0 && right >= 0)
        {
            res = left + right + 2;
            return -1;
        }
        return left >= 0 ? left + 1 : (right >= 0 ? right + 1 : -1);
    }
};