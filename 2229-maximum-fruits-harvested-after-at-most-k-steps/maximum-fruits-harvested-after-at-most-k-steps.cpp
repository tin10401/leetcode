class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
       int i = upper_bound(begin(fruits), end(fruits), vector<int>{startPos - k}) - begin(fruits);
       int res = 0, sum = 0, n = fruits.size();
       for(int j = i; j < n && fruits[j][0] <= startPos + k; j++) 
       {
            sum += fruits[j][1];
            while(min(fruits[j][0] - fruits[i][0] + fruits[j][0] - startPos, startPos - fruits[i][0] + fruits[j][0] - fruits[i][0]) > k) sum -= fruits[i++][1];
            res = max(res, sum);
       }
       return res;
    }
};