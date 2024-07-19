class Solution {
public:
    vector<vector<char>> seats;
    bool check(int row, int col)
    {
        if(col && (seats[row][col - 1] == 'x' || (row && seats[row - 1][col - 1] == 'x'))) return false;
        if(col < seats[0].size() - 1 && (seats[row][col + 1] == 'x' || (row && seats[row - 1][col + 1] == 'x'))) return false;
        return true;
    }
    
    int dp[9][1 << 9][1 << 9];
    int compute(int row, int col, int mask, int prev)
    {
        if(row == seats.size()) return 0;
        int& res = dp[row][mask][prev];
        if(col == 0 && res != -1) return res;
        if(col == seats[0].size()) return res = compute(row + 1, 0, 0, mask);
        res = compute(row, col + 1, mask, prev);
        if(seats[row][col] == '.' && check(row, col))
        {
            seats[row][col] = 'x';
            res = max(res, 1 + compute(row, col + 1, mask | (1 << col), prev));
            seats[row][col] = '.';
        }
        return res;
    }

    int maxStudents(vector<vector<char>>& seats) {
        memset(dp, -1, sizeof(dp));
        this->seats = seats;
        return compute(0, 0, 0, 0);
    }
};