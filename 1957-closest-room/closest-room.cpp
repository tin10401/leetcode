class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        auto compare = [](const vector<int>& a, const vector<int>& b)
        {
            return a[1] > b[1];
        };
        sort(begin(rooms), end(rooms), compare);
        vector<int> res(queries.size(), -1);
        for(int i = 0; i < queries.size(); i++) queries[i].push_back(i);
        sort(begin(queries), end(queries), compare);
        set<int> s;
        int i = 0;
        for(auto& q : queries)
        {
            int id = q[0], sz = q[1], index = q[2];
            while(i < rooms.size() && rooms[i][1] >= sz) s.insert(rooms[i++][0]);
            auto it = s.lower_bound(id);
            int curr = INT_MAX, ans = -1;
            if(it != s.end())
            {
                int temp = abs(*it - id);
                if(temp < curr)
                {
                    curr = temp;
                    ans = *it;
                }
            }
            if(it != s.begin())
            {
                it--;
                int temp = abs(*it - id);
                if(temp <= curr)
                {
                    if(temp == curr) ans = min(ans, *it);
                    else ans = *it;
                    curr = temp;
                }
            }
            res[index] = ans;
        }
        return res;
    }
};