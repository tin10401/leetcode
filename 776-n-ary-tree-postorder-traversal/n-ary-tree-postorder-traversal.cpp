/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root) return {};
        vector<int> res;
        stack<Node*> s;
        s.push(root);
        unordered_set<Node*> vis;
        while(!s.empty())
        {
            auto node = s.top();
            if(vis.count(node) || node->children.empty())
            {
                res.push_back(node->val);
                s.pop();
                continue;
            }
            vis.insert(node);
            int n = node->children.size();
            for(int i = n - 1; i >= 0; i--)
            {
                s.push(node->children[i]);
            }
        }
        return res;
    }
};