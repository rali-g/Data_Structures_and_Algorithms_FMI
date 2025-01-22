class Solution {
public:
    int partition(vector<string>& nums, int left, int right)
    {
        int pivotIndex = rand() % (right - left + 1) + left;
        swap(nums[pivotIndex], nums[right]);
        int ind = left;
        for(int i = left; i < right; i++)
        {
            if(nums[i].size() > nums[right].size() || (nums[i].size() == nums[right].size() 
            && nums[i] > nums[right]))
            {
                std::swap(nums[ind], nums[i]);
                ind++;
            }
        }
        std::swap(nums[ind], nums[right]);
        return ind;
    }
    void partialQuickSort(vector<string>& nums, int left, int right, int k)
    {
        int pivotIndex = partition(nums, left, right);
        if(pivotIndex == k - 1)
            return;
        if(pivotIndex < k - 1)
        {
            partialQuickSort(nums, pivotIndex + 1, right, k);
        }
        else
        {
            partialQuickSort(nums, left, pivotIndex - 1, k);
        }
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        srand(time(0));
        if(nums.size() == 1)
        {
            return nums[0];
        }
        partialQuickSort(nums, 0, nums.size() - 1, k);
        return nums[k - 1];
    }
};