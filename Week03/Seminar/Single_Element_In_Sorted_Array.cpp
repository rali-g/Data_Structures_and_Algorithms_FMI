class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if((mid - 1 < 0 || nums[mid - 1] != nums[mid]) && 
            (mid + 1 >= nums.size() || nums[mid + 1] != nums[mid]))
            {
                return nums[mid];
            }
            if((mid + 1 < nums.size() && nums[mid] == nums[mid + 1] && (mid + 1) % 2 == 0)
            || (mid - 1 >= 0 && nums[mid] == nums[mid - 1] && (mid - 1) % 2 == 1))
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return -1;
    }
};