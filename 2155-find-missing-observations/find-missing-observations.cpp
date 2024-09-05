class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        const int m = rolls.size();
        const int target = mean * (m + n);
        const int sum = accumulate(rolls.begin(), rolls.end(), 0);
        const int diff = target - sum;
        if (diff < n || diff > 6 * n)
            return {};

        if (diff % n == 0)
            return vector<int>(n, diff / n);

        vector<int> result(n, diff / n);
        for (int i = 0; i < diff % n; ++i) {
            result[i]++;
        }
        return result;
    }
};