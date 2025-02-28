class KthLargest {
public:
    priority_queue<int, vector<int>, std::greater<>> minHeap;
    int k = 0;
    KthLargest(int k, vector<int>& nums) : k(k) {
        for(auto n : nums)
        {
            minHeap.push(n);
        }
        while(minHeap.size() > k)
        {
            minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k)
            minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */