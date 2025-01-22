class Solution {  //practicing Quick Sort
public:
    int partition(vector<int>& arr, int left, int right)
    {
        int pivot = arr[right];
        int iter = left;
        for(int i = left; i < right; i++)
        {
            if(arr[i] > pivot)
            {
                swap(arr[i], arr[iter]);
                iter++;
            }
        }
        swap(arr[iter], arr[right]);
        return iter;
    }
    void partialQuickSort(vector<int>& nums, int left, int right, int k)
    {
        if(left < right)
        {
            int index = partition(nums, left, right);
            if(index == k - 1)
                return;
            if(index < k - 1)
            {
                partialQuickSort(nums, index + 1, right, k);
            }
            else
            {
                partialQuickSort(nums, left, index - 1, k);
            }
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() == 1)
            return nums[0];
        partialQuickSort(nums, 0, nums.size() - 1, k);
        return nums[k - 1];
    }
};