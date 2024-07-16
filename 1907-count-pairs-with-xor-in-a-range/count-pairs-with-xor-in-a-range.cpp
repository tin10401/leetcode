class Trie
{
    public:
    Trie* children[2]{};
    int count = 0;
    Trie() : count(0), children{} {}

    void insert(int num)
    {
        Trie* curr = this;
        for(int i = 31; i >= 0; i--)
        {
            int bits = (num >> i) & 1;
            if(!curr->children[bits]) curr->children[bits] = new Trie();
            curr = curr->children[bits];
            curr->count++;
        }
    }

    int search(int num, int limit)
    {
        int res = 0;
        Trie* curr = this;
        for(int i = 31; i >= 0; i--)
        {
            int numBit = (num >> i) & 1;
            int limitBit = (limit >> i) & 1;
            if(limitBit == 1)
            {
                if(curr->children[numBit]) res += curr->children[numBit]->count;
                if(!curr->children[!numBit]) break;
                curr = curr->children[!numBit];
            }
            else
            {
                if(!curr->children[numBit]) break;
                curr = curr->children[numBit];
            }
        }
        return res;
    }
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int res = 0;
        Trie* trie = new Trie();
        for(auto& num : nums)
        {
            res += trie->search(num, high + 1) - trie->search(num, low);
            trie->insert(num);
        }
        return res;
    }
};