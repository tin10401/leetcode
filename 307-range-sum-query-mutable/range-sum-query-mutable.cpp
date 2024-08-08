class NumArray {
public:
    vector<int> block, nums;
    int len;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        len = ceil((double)sqrt(n));
        block.resize(len);
        for(int i = 0; i < nums.size(); i++) 
        {
            block[i / len] += nums[i];
        }
    }
    
    void update(int index, int val) {
        block[index / len] -= nums[index];
        block[index / len] += val;
        nums[index] = val;

    }
    
    int sumRange(int left, int right) {
        int res = 0;
        if(left / len == right / len)
        {
            for(int i = left; i <= right; i++) res += nums[i];
            return res;
        }        
        int l = left / len + 1;
        int r = right / len - 1;
        while(left / len < l) res += nums[left++];
        while(l <= r) res += block[l++];
        while(right / len > r) res += nums[right--];
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */