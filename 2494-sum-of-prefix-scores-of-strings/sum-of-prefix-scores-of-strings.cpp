class Trie
{
    public:
    Trie* children[26];
    int count = 0;
    Trie() : children{}, count(0) {}

    void insert(const string& word)
    {
        Trie* curr = this;
        for(auto& ch : word)
        {
            if(!curr->children[ch - 'a']) curr->children[ch - 'a'] = new Trie();
            curr = curr->children[ch - 'a'];
            curr->count++;
        }
    }

    int search(const string& word)
    {
        int res = 0;
        Trie* curr = this;
        for(auto& ch : word)
        {
            curr = curr->children[ch - 'a'];
            res += curr->count;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> res;
        Trie* trie = new Trie();
        for(auto& word : words) trie->insert(word);
        for(auto& word : words)
        {
            res.push_back(trie->search(word));
        }
        return res;
    }
};