class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(begin(citations), end(citations));
        int left = 0, right = citations.back(), res = -1;
        while(left <= right)
        {
            int middle = left + (right - left) / 2;
            auto it = lower_bound(begin(citations), end(citations), middle);
            int dis = distance(it, end(citations));
            if(dis >= middle)
            {
                res = middle;
                left = middle + 1;
            }
            else right = middle - 1;
        }
        return res;
    }
};