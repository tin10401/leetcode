class Trie
{
    public:
    Trie* children[2]{};
    int count;
    Trie() : count(0), children{} {}
    void insert(const int num)
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

    void erase(const int num)
    {
        Trie* curr = this;
        for(int i = 31; i >= 0; i--)
        {
            int bits = (num >> i) & 1;
            if(--curr->children[bits]->count == 0) 
            {
                curr->children[bits] = nullptr;
                break;
            }
            curr = curr->children[bits];
        }
    }
    
    int search(int num)
    {
        Trie* curr = this;
        int res = 0;
        for(int i = 31; i >= 0; i--)
        {
            int bits = (num >> i) & 1;
            if(curr->children[!bits])
            {
                res |= (1 << i);
                curr = curr->children[!bits];
            }
            else curr = curr->children[bits];
        }
        return res;
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int res = 0;
        Trie* trie = new Trie();
        for(int left = 0, right = 0; right < nums.size(); right++)
        {
            while(nums[right] - nums[left] > nums[left])
            {
                trie->erase(nums[left++]);
            }
            trie->insert(nums[right]);
            if(left != right) res = max(res, trie->search(nums[right]));
        }
        return res;
    }
};