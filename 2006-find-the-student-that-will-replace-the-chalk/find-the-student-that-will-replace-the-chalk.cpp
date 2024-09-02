class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = accumulate(begin(chalk), end(chalk), 0LL);
        k %= sum;
        for(int i = 0; i < chalk.size(); i++)
        {
            k -= chalk[i];
            if(k < 0) return i;
        }
        return k;
    }
};