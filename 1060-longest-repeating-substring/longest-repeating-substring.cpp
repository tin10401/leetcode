class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.size(), left = 0, right = n - 1;
        auto check = [&](int middle)
        {
            unordered_set<string_view> vis;
            for(int i = 0; i < n - middle + 1; i++)
            {
                auto temp = string_view(s).substr(i, middle);
                if(vis.count(temp)) return true;
                vis.insert(temp);
            }
            return false;
        };
        while(left <= right)
        {
            int middle = left + (right - left) / 2;
            if(check(middle)) left = middle + 1;
            else right = middle - 1;
        }
        return right;
    }
};