class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater());
        int ans = 0;
        // for (auto i : nums) cout << i << " ";
        // cout << endl;
        unordered_map<int, int> count;
        unordered_set<int> s;
        for (int index = 0; index < n; index++){
            int c = 1;
            while (index + 1 < n && nums[index + 1] == nums[index]) c++, index++;
            ans += c * (c - 1) / 2;
            ans += count[nums[index]] * c;
            string curr = to_string(nums[index]);
            int k = curr.length();
            for (int i = 0; i < k; i++){
                for (int j = i; j < k; j++){
                    swap(curr[i], curr[j]);
                    for (int a = 0; a < k; a++){
                        for (int b = a; b < k; b++){
                            swap(curr[a], curr[b]);
                            s.insert(stoi(curr));
                            swap(curr[a], curr[b]);
                        }
                    }
                    swap(curr[i], curr[j]);
                }
            }
            for (int temp : s) count[temp] += c;
            s.clear();
        }
        return ans;
    }
};