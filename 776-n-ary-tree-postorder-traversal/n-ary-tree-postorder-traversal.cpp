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
        while(!s.empty())
        {
            auto node = s.top();
            bool ok = false;
            int n = node->children.size();
            for(int i = n - 1; i >= 0; i--)
            {
                auto nei = node->children[i];
                if(nei->val != INT_MIN) {ok = true, s.push(nei);}
            }
            if(!ok) {res.push_back(node->val); node->val = INT_MIN; s.pop();}
        }
        return res;
    }
};