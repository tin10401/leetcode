class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> s;
        int n = heights.size();
        vector<int> res(n);
        for(int i = n - 1; i >= 0; i--)
        {
            int count = 0;
            while(!s.empty() && heights[s.top()] < heights[i]) 
            {
                count++;
                s.pop();
            }
            int ans = count + !s.empty();
            res[i] = ans;
            s.push(i);
        }
        return res;
    }
};