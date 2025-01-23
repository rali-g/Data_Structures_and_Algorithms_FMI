class Solution {
public:
    int binarySearch(vector<int>& nums, int start, int end)
    {
        while(true)
        {
            int mid = start + (end - start) / 2;
            if(nums[end] > nums[mid])
            {
                end = mid;
                continue;
            }
            if(nums[end] < nums[mid])
            {
                start = mid + 1;
                continue;
            }
            if(nums[end] == nums[mid] && start != end)  //search in both halves
            {
                int leftValue = binarySearch(nums, start, mid);
                if(leftValue != nums[mid])
                {
                    return leftValue;
                }
                return binarySearch(nums, mid + 1, end);
            }
            return nums[mid];  //if start == end
        }
    }
    int findMin(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size() - 1);
    }
};