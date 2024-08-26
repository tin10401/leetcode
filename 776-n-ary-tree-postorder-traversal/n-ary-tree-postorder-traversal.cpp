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
    vector<int> list;
    vector<int> postorder(Node* root) {
        if(root == nullptr)
        {
            return list;
        }
        if(!root->children.empty())
        {
            int size = root->children.size();
            for(int i = 0; i < size; i++)
            {
                postorder(root->children[i]);
            }
            
        }
        list.push_back(root->val);
        return list;
    }
};