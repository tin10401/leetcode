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
    vector<int> temp;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr)
        {
            return temp;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        temp.push_back(root->val);
        return temp;
    }
};