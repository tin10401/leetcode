class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0; i < mapping.size(); i++)
        {
            mp[i] = mapping[i];
        }
        vector<array<int, 3>> list;
        for(int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            string s = to_string(num);
            int newNum = 0;
            for(auto& ch : s)
            {
                newNum = newNum * 10 + mp[ch - '0'];
            }
            list.push_back({newNum, num, i});
        } 
        auto compare = [](const array<int, 3>& a, const array<int, 3>& b)
        {
            if(a[0] == b[0]) return a[2] < b[2];
            return a[0] < b[0];
        };
        sort(begin(list), end(list), compare);
        vector<int> res;
        for(auto& [_, num, __] : list) res.push_back(num);
        return res;
    }
};