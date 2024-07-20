#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        int m = T.length(), n = S.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int j = 0; j <= n; j++) {
            dp[0][j] = j + 1;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (T[i - 1] == S[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        int start = 0, len = n + 1;
        for (int j = 1; j <= n; j++) {
            if (dp[m][j] != 0) {
                if (j - dp[m][j] + 1 < len) {
                    start = dp[m][j] - 1;
                    len = j - dp[m][j] + 1;
                }
            }
        }

        return len == n + 1 ? "" : S.substr(start, len);
    }
};
