class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() <= 1) {
            return s;
        }

        int max_len = 1;
        std::string max_str = s.substr(0, 1);
        std::string modified_s = "#" + join(s, '#') + "#";
        std::vector<int> dp(modified_s.size(), 0);
        int center = 0;
        int right = 0;

        for (int i = 0; i < modified_s.size(); ++i) {
            if (i < right) {
                dp[i] = std::min(right - i, dp[2 * center - i]);
            }
            while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < modified_s.size() && modified_s[i - dp[i] - 1] == modified_s[i + dp[i] + 1]) {
                dp[i]++;
            }
            if (i + dp[i] > right) {
                center = i;
                right = i + dp[i];
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                max_str = modified_s.substr(i - dp[i], 2 * dp[i] + 1);
                max_str.erase(std::remove(max_str.begin(), max_str.end(), '#'), max_str.end());
            }
        }

        return max_str;
    }

private:
    std::string join(const std::string& s, char delimiter) {
        std::string result;
        for (char c : s) {
            result += c;
            result += delimiter;
        }
        result.pop_back(); // Remove the last delimiter
        return result;
    }
};
