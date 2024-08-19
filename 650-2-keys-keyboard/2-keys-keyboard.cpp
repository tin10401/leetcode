class Solution {
public:
    int minSteps(int n) {
        queue<tuple<int, int, int>> q;
        q.push({1, 0, 0});
        bool vis[1001][1001] = {};
        vis[1][0] = true;
        while(!q.empty())
        {
            auto [curr, prev, count] = q.front();
            q.pop();
            if(curr == n) return count;
            if(curr > n) continue;
            if(!vis[curr][curr])
            {
                vis[curr][curr] = true;
                q.push({curr, curr, count + 1});
            }
            if(curr + prev <= n && !vis[curr + prev][prev])
            {
                vis[curr + prev][prev] = true;
                q.push({curr + prev, prev, count + 1});
            }
        }
        return -1;
    }
};