class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        auto getMask = [](const string& word)
        {
            int mask = 0;
            for(auto& ch : word)
            {
                mask |= (1 << (ch - 'a'));
            }
            return mask;
        };
        unordered_map<int, int> mp;
        for(auto& word : words)
        {
            mp[getMask(word)]++;
        }
        vector<int> res;
        for(auto& it : puzzles)
        {
            unordered_set<char> t(begin(it), end(it));
            vector<char> list(begin(t), end(t));
            char ch = it[0];
            int index = find(begin(list), end(list), it[0]) - begin(list);
            int n = list.size();
            int total = 0;
            for(int mask = 1; mask < 1 << n; mask++)
            {
                int newMask = 0;
                if((mask >> index) & 1) continue;
                for(int i = 0; i < n; i++)
                {
                    if((mask >> i) & 1)
                    {
                        newMask |= (1 << (list[i] - 'a'));
                    }
                }
                newMask |= (1 << (ch - 'a'));
                total += mp[newMask];
            }
            total += mp[(1 << (ch - 'a'))];
            res.push_back(total);
        }
        return res;
    }
};