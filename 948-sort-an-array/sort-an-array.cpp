class Solution {
public:
    void sort(vector<int>& nums, int left, int right)
    {
        if(left == right)
        {
            return;
        }
        int middle = left + (right - left) / 2;
        sort(nums, left, middle);
        sort(nums, middle + 1, right);
        mergeSort(nums, left, middle, right);
    }
    void mergeSort(vector<int>& nums, int left, int middle, int right)
    {
        vector<int> L(nums.begin() + left, nums.begin() + middle + 1);
        int i = 0;
        int j = middle + 1;
        int k = left;
        while(i < L.size() && j <= right)
        {
            if(L[i] < nums[j])
            {
                nums[k++] = L[i++];
            }
            else
            {
                nums[k++] = nums[j++];
            }
        }
        while(i < L.size())
        {
            nums[k++] = L[i++];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size() - 1);
        return nums;
    }
};