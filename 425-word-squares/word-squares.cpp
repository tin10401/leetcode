struct Node
{
    Node* children[26]{};
    vector<string> wordSet;
};

static Node nodes[(int)1e5]{};

class Trie
{
    public:
    Node* root;
    int count = 0;
    Node* newNode()
    {
        nodes[count] = Node();
        return &nodes[count++];
    }

    Trie()
    {
        root = newNode();
    }

    void insert(const vector<string>& words)
    {
        root = newNode();
        for(auto& word : words)
        {
            Node* curr = root;
            for(auto& ch : word)
            {
                if(!curr->children[ch - 'a']) curr->children[ch - 'a'] = newNode();
                curr = curr->children[ch - 'a'];
                curr->wordSet.push_back(word);
            }
        }
    }

    vector<string> generate(const string& word)
    {
        Node* curr = root;
        for(auto& ch : word)
        {
            if(!curr->children[ch - 'a']) return {};
            curr = curr->children[ch - 'a'];
        }
        return curr->wordSet;
    }
};
class Solution {
public:
    vector<vector<string>> res;
    vector<string> s;
    int n;
    Trie trie;
    
    void dfs(int index)
    {
        if(index == n)
        {
            res.push_back(s);
            return;
        }
        Node* curr = trie.root;
        string w;
        for(auto& word : s) w += word[index];
        for(auto& w : trie.generate(w))
        {
            s.push_back(w);
            dfs(index + 1);
            s.pop_back();
        }
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        trie.insert(words);
        n = words[0].size();
        for(auto& word : words)
        {
            s = {word};
            dfs(1);
        }
        return res;
        
    }
};