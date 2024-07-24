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
    int depth[100001] = {}, height[100001] = {}, maxHeight[100001] = {}, secondMaxHeight[100001] = {};
    int dfs(TreeNode* root, int currDepth)
    {
        if(!root) return 0;
        int curr = root->val;
        depth[curr] = currDepth;
        height[curr] = 1 + max(dfs(root->left, currDepth + 1), dfs(root->right, currDepth + 1));
        if(height[curr] > maxHeight[currDepth])
        {
            secondMaxHeight[currDepth] = maxHeight[currDepth];
            maxHeight[currDepth] = height[curr];
        }
        else
        {
            secondMaxHeight[currDepth] = max(secondMaxHeight[currDepth], height[curr]);
        }
        return height[curr];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root, 0);
        vector<int> res; 
        for(auto& q : queries)
        {
            int currDepth = depth[q];
            int ans = currDepth + (maxHeight[currDepth] == height[q] ? secondMaxHeight[currDepth] : maxHeight[currDepth]) - 1;
            res.push_back(ans);
        }
        return res;
    }
};