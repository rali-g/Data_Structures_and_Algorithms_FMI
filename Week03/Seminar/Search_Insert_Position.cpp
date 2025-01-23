class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        if(nums[0] >= target)
            return 0;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(mid + 1 >= nums.size() || (nums[mid] < target && nums[mid + 1] >= target))
            {
                return mid + 1;
            }
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};