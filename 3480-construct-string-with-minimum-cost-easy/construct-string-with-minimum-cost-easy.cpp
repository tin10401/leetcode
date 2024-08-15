struct Node
{
    Node* sfx, *dict, *children[26];
    int id = -1;
};

static Node nodes[(int)5e4 + 1]{};

class Trie
{
    public:
    Node* root;
    int count = 0, n;
    vector<int> costs, len, dp;
    string s;
    Node* newNode()
    {
        nodes[count] = Node();
        return &nodes[count++];
    }
    Trie(vector<string>& words, vector<int>& costs, string target)
    {
        s = target, this->costs = costs, n = target.size(), dp.resize(n + 1, 1e9);
        root = newNode();
        root->sfx = root->dict = root;
        for(int i = 0; i < words.size(); i++)
        {
            Node* curr = root;
            for(auto& ch : words[i])
            {
                if(!curr->children[ch - 'a']) curr->children[ch - 'a'] = newNode();
                curr = curr->children[ch - 'a'];
            }
            len.push_back(words[i].size());
            if(curr->id == -1 || costs[curr->id] > costs[i]) curr->id = i;
        }

        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* par = q.front();
            q.pop();
            for(int i = 0; i < 26; i++)
            {
                Node* child = par->children[i];
                if(!child) continue;
                Node* suff = par->sfx;
                while(suff != root && !suff->children[i]) suff = suff->sfx;
                if(par != root && suff->children[i]) child->sfx = suff->children[i];
                else child->sfx = root;

                child->dict = child->sfx->id == -1 ? child->sfx->dict : child->sfx;
                q.push(child);
            }
        }
    }

    void queries(Node*& prev, int i, char ch)
    {
        while(prev != root && !prev->children[ch - 'a']) prev = prev->sfx;
        if(prev->children[ch - 'a']) 
        {
            prev = prev->children[ch - 'a'];
            Node* curr = prev->id == -1 ? prev->dict : prev;
            while(curr->id != -1)
            {
                int j = curr->id;
                dp[i] = min(dp[i], dp[i - len[j]] + costs[j]);
                curr = curr->dict;
            }
        }
    }


    int get()
    {
        dp[0] = 0;
        Node* prev = root;
        for(int i = 1; i <= n; i++)
        {
            queries(prev, i, s[i - 1]);
        }
        return dp[n] == 1e9 ? -1 : dp[n];
    }  
};

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        Trie trie(words, costs, target);
        return trie.get();
    }
};