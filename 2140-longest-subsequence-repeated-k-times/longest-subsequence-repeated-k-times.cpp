class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        auto check = [&](const string& a)
        {
            int n = s.size(), m = a.size(), i = 0, j = 0;
            while(i < n && j < m * k)
            {
                if(s[i] == a[j % m]) j++;
                i++;
            }
            return j == m * k;
        };
        string res;
        array<int, 26> counter;
        for(auto& ch : s) counter[ch - 'a']++;
        queue<pair<string, array<int, 26>>> q;
        q.push({"", {}});
        while(!q.empty())
        {
            auto [curr, count] = q.front();
            q.pop();
            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                if((count[ch - 'a'] + 1) * k > counter[ch - 'a']) continue;
                string temp = curr + ch;
                if(check(temp))
                {
                    if(temp.size() > res.size() || temp > res) res = temp;
                    array<int, 26> next = count;
                    next[ch - 'a']--;
                    q.push({temp, next});
                }
            }
        }
        return res;
    }
};