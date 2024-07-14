class Solution {
public:
    // unordered_map<string_view, vector<int>> dp;
    unordered_set<int> dp[32][32];
    void dfs(const string& s, int leftPart, int rightPart)
    {
        // auto curr = string_view(s).substr(leftPart, rightPart - leftPart + 1);
        auto& res = dp[leftPart][rightPart];
        if(!res.empty()) return;
        for(int i = leftPart; i < rightPart; i++)
        {
            char ch = s[i];
            if(!isdigit(ch))
            {
                dfs(s, leftPart, i);
                dfs(s, i + 1, rightPart);
                for(auto& l : dp[leftPart][i])
                {
                    for(auto& r : dp[i + 1][rightPart])
                    {
                        int ans = ch == '+' ? l + r : l * r;
                        if(ans <= 1000) res.insert(ans);
                    }
                }
            }
        }
        if(res.empty()) res.insert(stoi(s.substr(leftPart, rightPart - leftPart + 1)));
    }
    int scoreOfStudents(string s, vector<int>& answers) {
        int n = s.size();
        using ll = long long;
        stack<int> st;
        int curr = 0;
        char last = '+';
        for(auto& ch : s)
        {
            if(isdigit(ch))
            {
                curr = curr * 10 + (ch - '0');
            }
            else
            {
                if(last == '+') st.push(curr);
                else 
                {
                    auto num = st.top();
                    st.pop();
                    st.push(num * curr);
                }
                curr = 0;
                last = ch;
            }
        }
        int correct = 0;
        if(last == '*') 
        {
            auto num = st.top();
            st.pop();
            correct = num * curr;
        }
        else
        {
            correct = curr;
        }
        while(!st.empty())
        {
            correct += st.top();
            st.pop();
        }
        dfs(s, 0, s.size());
        unordered_set<int> &partiallyCorrect = dp[0][n];
        int res = 0;
        for(auto& num : answers)
        {
            if(num == correct) res += 5;
            else if(partiallyCorrect.count(num)) res += 2;
        }
        return res;
    }
};