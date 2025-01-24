class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;
        queue<int> q; //sliding window
        vector<int> result;
        for(int i = 0; i < k; i++)
        {
            while(!deq.empty() && deq.back() < nums[i])
            {
                deq.pop_back();
            }
            deq.push_back(nums[i]);
            q.push(nums[i]);
        }
        result.push_back(deq.front());
        for(int i = k; i < nums.size(); i++)
        {
            if(q.front() == deq.front())
            {
                deq.pop_front();
            }
            while(!deq.empty() && deq.back() < nums[i])
            {
                deq.pop_back();
            }
            deq.push_back(nums[i]);
            result.push_back(deq.front());
            q.pop();
            q.push(nums[i]);
        }
        return result;
    }
};