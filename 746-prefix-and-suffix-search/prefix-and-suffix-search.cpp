struct Node
{
    unordered_map<int, Node*> children;
    int index = -1;
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
        for(int i = 0; i < words.size(); i++)
        {
            Node* curr = root;
            for(int j = 0, k = words[i].size() - 1; j < words[i].size() && k >= 0; j++, k--)
            {
                int key = words[i][j] * 26 + words[i][k];
                if(!curr->children.count(key)) curr->children[key] = newNode();
                curr = curr->children[key];
                curr->index = i;
            }
        }
    }


    int dfs(Node* curr, int index, const string& s, int update)
    {
        if(index < 0 || index == s.size()) return curr->index;
        int res = -1;
        for(char ch = 'a'; ch <= 'z'; ch++)
        {
            int key = update == 1 ? s[index] * 26 + ch : ch * 26 + s[index];
            if(curr->children.count(key))
            {
                res = max(res, dfs(curr->children[key], index + update, s, update));
            }
        }
        return res;
    }

    int search(const string& prefix, const string& suffix)
    {
        Node* curr = root;
        int i = 0, j = suffix.size() - 1;
        for(; i < prefix.size() && j >= 0; i++, j--)
        {
            int key = prefix[i] * 26 + suffix[j];
            if(!curr->children.count(key)) return -1;
            curr = curr->children[key];
        }
        if(i == prefix.size() && j == -1) return curr->index;
        if(i == prefix.size()) return dfs(curr, j, suffix, -1);
        return dfs(curr, i, prefix, 1);
    }
};

class WordFilter {
public:
    Trie trie;
    WordFilter(vector<string>& words) {
        trie.insert(words);
    }
    
    int f(string pref, string suff) {
        return trie.search(pref, suff);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */