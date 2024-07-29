class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0, n = rating.size();
        for(int i = 1; i < n; i++)
        {
            int less[2] = {}, greater[2] = {};
            for(int j = 0; j < n; j++)
            {
                if(rating[j] < rating[i]) less[j < i]++;
                else if(rating[j] > rating[i]) greater[j < i]++;
            }
            res += less[0] * greater[1] + less[1] * greater[0];
        }
        return res;
    }
};