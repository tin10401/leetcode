#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        ordered_set s;
        vector<double> res;
        for(int i = 0; i < nums.size(); i++)
        {
            s.insert({nums[i], i});
            if(i >= k - 1)
            {
                auto it = s.find_by_order(k / 2);
                double total = it->first;
                if(k % 2 == 0) total = (total + prev(it)->first) / 2;
                res.push_back(total);
                s.erase(s.lower_bound({nums[i - k + 1], i - k + 1}));
            }
        }
        return res;
    }
};