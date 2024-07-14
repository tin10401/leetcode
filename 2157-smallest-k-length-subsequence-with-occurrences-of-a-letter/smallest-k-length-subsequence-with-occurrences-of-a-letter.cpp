class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        stack<char> st;
        int cnt = count(begin(s), end(s), letter), n = s.size();
        for(int i = 0; i < n; i++)
        {
            char ch = s[i];
            while(!st.empty() && 
                (st.top() > ch && st.size() + n - i > k && (st.top() != letter || cnt > repetition) || st.size() + repetition > k)
            ) 
            {
                repetition += st.top() == letter;
                st.pop();
            }
            if(st.size() < k)
            {
                st.push(ch);
                repetition -= ch == letter;
            }
            cnt -= letter == ch;
        }
        string res;
        while(!st.empty()) 
        {
            res += st.top();
            st.pop();
        }
        return string(rbegin(res), rend(res));
    }
};