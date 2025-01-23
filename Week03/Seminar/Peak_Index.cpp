class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(mid + 1 < arr.size() && mid - 1 >= 0 && 
            arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            if(mid + 1 < arr.size() && arr[mid] < arr[mid + 1])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};