class Solution {
public:
    vector<int> nums, curr;
    int n;
    Solution(vector<int>& nums) {
        this->n = nums.size();
        this->nums = nums;
        curr = nums;
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        for(int i = 0; i < n; i++)
        {
            int index = rand() % n;
            swap(curr[i], curr[index]);
        }
        return curr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */