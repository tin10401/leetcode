class Solution {
public:
    int superpalindromesInRange(string l, string r) {
        using ll = unsigned long long;
        ll left = stoll(l), right = stoll(r), res = 0;
        auto isValid = [&](ll num)
        {
            string s = to_string(num);
            return s == string(rbegin(s), rend(s));
        };
        for(int i = 1; i <= 1e5; i++)
        {   
            string s = to_string(i);
            string rev = s;
            rev.pop_back();
            reverse(begin(rev), end(rev));
            ll curr = stoll(s + rev);
            curr *= curr;
            if(curr >= left && curr <= right && isValid(curr)) res++;
            if(curr > right) break;
            s += string(rbegin(s), rend(s));
            curr = stoll(s);
            curr *= curr;
            if(curr >= left && curr <= right && isValid(curr)) res++;
        }
        return res;
    }
};