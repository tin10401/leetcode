class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
       using ll = long long;
       ll res = 0, sum = 0;
       priority_queue<pair<ll, ll>> minHeap;
       for(ll left = 0, right = 0; right < chargeTimes.size(); right++)
       {
            minHeap.push({(ll)chargeTimes[right], right});
            sum += runningCosts[right];
            while(!minHeap.empty() && (minHeap.top().second < left || (right - left + 1) * sum + minHeap.top().first > budget))
            {
                if(minHeap.top().second < left) minHeap.pop();
                else
                {
                    sum -= runningCosts[left++];
                }
            }
            res = max(res, right - left + 1);
       }
       return res;
    }
};