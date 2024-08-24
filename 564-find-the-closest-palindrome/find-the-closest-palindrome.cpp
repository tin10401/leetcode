#include <string>
#include <algorithm>
#include <climits>
#include <cstdlib>

class Solution {
public:
    std::string nearestPalindromic(std::string n) {
        long N = std::stol(n);
        long S = previous(std::to_string(N - 1));
        long L = next(std::to_string(N + 1));
        return std::to_string(L - N < N - S ? L : S);
    }

private:
    long previous(std::string s) {
        int n = s.length();
        for (int i = 0; i < n / 2; ++i) {
            while (s[i] != s[n - 1 - i]) {
                decrement(s, n - 1 - i);
                if (s[0] == '0') return std::stol(s);
            }
        }
        return std::stol(s);
    }

    void decrement(std::string& s, int i) {
        while (s[i] == '0') s[i--] = '9';
        s[i]--;
    }

    long next(std::string s) {
        int n = s.length();
        for (int i = 0; i < n / 2; ++i) {
            while (s[i] != s[n - 1 - i]) {
                increment(s, n - 1 - i);
            }
        }
        return std::stol(s);
    }

    void increment(std::string& s, int i) {
        while (s[i] == '9') s[i--] = '0';
        s[i]++;
    }
};
