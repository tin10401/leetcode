class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(begin(houses), end(houses));
        sort(begin(heaters), end(heaters));
        int left = 0, right = 1e9, res = -1;
        auto check = [&](int n)
        {
            int i = 0;
            for(auto& h : heaters)
            {
                while(i < houses.size() && abs(houses[i] - h) <= n) i++;
                if(i < houses.size() && houses[i] < h) return false;
            }
            return i == houses.size();
        };
        while(left <= right)
        {
            int middle = left + (right - left) / 2;
            if(check(middle)) res = middle, right = middle - 1;
            else left = middle + 1;
        }
        return res;
    }
};