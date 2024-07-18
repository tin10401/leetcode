class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(begin(buses), end(buses));
        sort(begin(passengers), end(passengers));
        auto check = [&](int n)
        {
            int i = 0;
            for(auto& b : buses)
            {
                int current = 0;
                while(i < passengers.size() && passengers[i] <= min(n, b) && current < capacity) i++, current++;
                if(current == capacity) continue;
                if(n <= b) return true;
            }
            return false;
        };
        int left = 0, right = buses.back(), res = -1;
        while(left <= right)
        {
            int middle = left + (right - left) / 2;
            if(check(middle)) res = middle, left = middle + 1;
            else right = middle - 1;
        }
        unordered_set<int> s(begin(passengers), end(passengers));
        while(binary_search(passengers.begin(),passengers.end(),res)) --res;
        return res;
    }
};