class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> arr;
        for (int i = 0; i < n - 1; ++i) {
            arr.insert(i);
        }
        
        vector<int> result;
        for (const auto& query : queries) {
            int i = query[0];
            int j = query[1];
            
            // merge all edges between [i, j]
            // == remove all nodes [i + 1, i + 2 ... j - 1]
            auto it1 = arr.lower_bound(i + 1);
            auto it2 = arr.upper_bound(j - 1);
            
            arr.erase(it1, it2);
            result.push_back(arr.size());
        }
        return result;
    }
};
