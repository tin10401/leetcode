class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 0) return s;
        if(k == 1)
        {
            string res = s;
            for(int i = 1; i < s.size(); i++)
            {
                res = min(res, s.substr(i) + s.substr(0, i));
            }
            return res;
        }
        sort(begin(s), end(s));
        return s;
    }
};