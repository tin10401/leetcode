class Solution {
public:
    string s;
    int k;
    unordered_set<char> vis;
    bool check(const string& b)
    {
        int n = s.size(), m = b.size(), i = 0, j = 0;
        while(i < n && j < m * k)
        {
            if(s[i] == b[j % m]) j++;
            i++;
        }
        return j == m * k;
    }
    vector<string> generate()
    {
        vector<string> curr;
        vector<string> temp;
        while(true)
        {
            temp.clear();
            if(curr.empty())
            {
                for(auto& ch : vis)
                {
                    string curr;
                    curr += ch;
                    if(check(curr)) temp.push_back(curr);
                }
            }
            else
            {
                for(auto& str : curr)
                {
                    for(auto& ch : vis)
                    {
                        string curr = str + ch;
                        if(check(curr)) temp.push_back(curr);
                    }
                }
            }
            if(temp.empty() || temp.front().size() * k > s.size()) return curr;
            curr = temp;
        }
        return curr;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        vis = {begin(s), end(s)};
        this->s = s, this->k = k;
        vector<string> res = generate();
        sort(rbegin(res), rend(res));
        return res.empty() ? "" : res.front();
    }
};