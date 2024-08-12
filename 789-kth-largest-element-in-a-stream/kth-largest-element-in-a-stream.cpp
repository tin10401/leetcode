auto compare = [](int a, int b) {return a > b;};
class KthLargest {
public:
    priority_queue<int, vector<int>, decltype(compare)> minHeap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums)
        {
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k )
        {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */