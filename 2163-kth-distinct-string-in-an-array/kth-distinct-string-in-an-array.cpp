class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> res;
        unordered_set<string> ban;
        for(auto& word : arr)
        {
            if(res.count(word))
            {
                ban.insert(word);
            }
            res.insert(word);
        }
        for(auto& word : arr)
        {
            if(!ban.count(word))
            {
                if(--k == 0)
                {
                    return word;
                }
            }
        }
        return "";
    }
};