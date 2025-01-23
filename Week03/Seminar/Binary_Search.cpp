class Solution {
public
    int search(vectorint& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left = right)
        {
            int mid = left - (left - right)  2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid]  target)
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