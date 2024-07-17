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
    vector<TreeNode*> res;
    unordered_set<int> vis;
    void dfs(TreeNode*& root)
    {
        if(!root)
        {
            return;
        }
        dfs(root->left);
        dfs(root->right);
        if(vis.count(root->val))
        {
            if(root->left)
            {
                res.push_back(root->left);
            }
            if(root->right)
            {
                res.push_back(root->right);
            }
            root = nullptr;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vis = {to_delete.begin(), to_delete.end()};
        dfs(root);
        if(root)
        {
            res.push_back(root);
        }
        return res;
    }
};