class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0, res = 0;
        for(auto& ch : s)
        {
            if(ch == '(') open++;
            else close++;
            if(close > open) close = 0, open = 0;
            if(open == close) res = max(res, open * 2);
        }
        close = 0, open = 0;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == '(') open++;
            else close++;
            if(close < open) open = 0, close = 0;
            else if(close == open) res = max(res, open * 2);
        }
        return res;
    }
};