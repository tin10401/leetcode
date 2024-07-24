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
    int level[100001] = {}, depth[100001] = {}, d1[100001] = {}, d2[100001] = {};
    int dfs(TreeNode* root, int d)
    {
        if(!root) return 0;
        level[root->val] = d;
        depth[root->val] = 1 + max(dfs(root->left, d + 1), dfs(root->right, d + 1));
        if(d1[d] < depth[root->val])
        {
            d2[d] = d1[d];
            d1[d] = depth[root->val];
        }
        else
        {
            d2[d] = max(d2[d], depth[root->val]);
        }
        return depth[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root, 0);
        vector<int> res;
        for(auto& q : queries)
        {
            int l = level[q];
            res.push_back(l + (d1[l] == depth[q] ? d2[l] : d1[l]) - 1);
        } 
        return res;
    }
};