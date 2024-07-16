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
    void helper(TreeNode* root, bool& found, string& str, int& value)
    {
        if(!root)
        {
            return;
        }
        if(root->val == value)
        {
            found = true;
            return;
        }
        helper(root->left, found, str, value);
        if(found)
        {
            str += "L";
            return;
        }
        helper(root->right, found, str, value);
        if(found)
        {
            str += "R";
            return;
        }
    }
    void removePre(string& a, string& b)
    {
        int size = min(a.size(), b.size());
        int i = 0;
        for(i = 0; i < size; i++)
        {
            if(a[i] != b[i])
            {
                break;
            }
        }
        a = a.substr(i);
        b = b.substr(i);
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string start = "";
        string dest = "";
        bool found = false;
        helper(root, found, start, startValue);
        found = false;
        helper(root, found, dest, destValue);
        reverse(start.begin(), start.end());
        reverse(dest.begin(), dest.end());
        removePre(start, dest);
        return string(start.size(), 'U') + dest;
    }
};