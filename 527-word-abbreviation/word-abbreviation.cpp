struct Node
{
    Node* children[26]{};
    int count = 0;
};

Node nodes[(int)1e5]{};
class Trie
{
    public:
    Node* root;
    int curr = 0;
    Node* newNode()
    {
        nodes[curr] = Node();
        return &nodes[curr++];
    }

    Trie()
    {
        root = newNode();
    }

    void insert(const string& word)
    {
        Node* curr = root;
        for(auto& ch : word)
        {
            if(!curr->children[ch - 'a']) curr->children[ch - 'a'] = newNode();
            curr = curr->children[ch - 'a'];
            curr->count++;
        }
    }

    int search(const string& word)
    {
        int index = 1;
        Node* curr = root;
        for(auto& ch : word)
        {
            curr = curr->children[ch - 'a'];
            if(curr->count == 1) return index;
            index++;
        }
        return index;
    }
};
class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        unordered_map<string, vector<pair<string, int>>> list;
        for(int i = 0; i < words.size(); i++)
        {
            string key = words[i].front() + to_string(words[i].size() - 2) + words[i].back();
            list[key].push_back({words[i], i});
        }
        vector<string> res(words.size());
        for(auto& it : list)
        {
           Trie root;
           for(auto& [w, i] : it.second) root.insert(w); 
           for(auto& [w, i] : it.second)
           {
                int index = root.search(w);
                string curr = to_string(w.size() - index - 1);
                if(w.size() - index - 1 > curr.size())
                {
                    res[i] = w.substr(0, index) + curr + w.back();
                }
                else res[i] = w;
           }
        }
        return res;
    }
};