class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        auto compute = [](auto& a, auto& b, auto& c)
        {
            return (c[0] - a[0]) * (b[1] - a[1]) - (b[0] - a[0]) * (c[1] - a[1]);
        };
        int n = trees.size();
        sort(begin(trees), end(trees));
        int curr = 0;
        set<vector<int>> res;
        do
        {
            int next = (curr + 1) % n;
            for(int i = 0; i < n; i++)
            {
                if(compute(trees[curr], trees[next], trees[i]) > 0) next = i;
            }
            for(int i = 0; i < n; i++)
            {
                if(compute(trees[curr], trees[next], trees[i]) == 0) res.insert(trees[i]);
            }
            curr = next;
        } while(curr);
        return vector<vector<int>>(begin(res), end(res));
    }
};