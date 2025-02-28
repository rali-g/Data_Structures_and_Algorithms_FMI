class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long result = 0;
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        for(int i = 0; i < k; i++)
        {
            double value = maxHeap.top();
            maxHeap.pop();
            result += value;
            maxHeap.push(ceil(class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long result = 0;
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        for(int i = 0; i < k; i++)
        {
            double value = maxHeap.top();
            maxHeap.pop();
            result += value;
            maxHeap.push(ceil(value / 3 * 1.0));
        }
        return result;
    }
};value / 3 * 1.0));
        }
        return result;
    }
};