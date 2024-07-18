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
    vector<int> helper(TreeNode*& root, const int& distance)
    {
        if(!root)
        {
            return {};
        }
        if(!root->left && !root->right)
        {
            return {1};
        }
        vector<int> left = helper(root->left, distance);
        vector<int> right = helper(root->right, distance);
        vector<int> curr;
        for(int d1 : left)
        {
            if(d1 + 1 < distance)
            {
                curr.push_back(d1 + 1);
            }
            for(int d2 : right)
            {
                if(d1 + d2 <= distance)
                {
                    res++;
                }
            }
        }
        for(int d : right)
        {
            if(d + 1 < distance)
            {
                curr.push_back(d + 1);
            }
        }
        return curr;
    }
    int countPairs(TreeNode* root, int distance) {
        helper(root, distance);
        return res;
    }
};