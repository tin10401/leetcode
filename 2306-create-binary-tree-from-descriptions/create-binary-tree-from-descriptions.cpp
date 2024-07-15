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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_map<int, int> parent;
        for(auto& it : descriptions)
        {
            int par = it[0];
            int child = it[1];
            int sign = it[2];
            TreeNode* first = nodeMap.count(par) ? nodeMap[par] : new TreeNode(par);
            TreeNode* second = nodeMap.count(child) ? nodeMap[child] : new TreeNode(child);
            nodeMap[par] = first;
            nodeMap[child] = second;
            if(sign == 1) first->left = second;
            else first->right = second;
            parent[child] = par;
        }      
        for(auto& it : descriptions)
        {
            if(!parent.count(it[0]))
            {
                return nodeMap[it[0]];
            }
        }
        return nullptr;
    }
};