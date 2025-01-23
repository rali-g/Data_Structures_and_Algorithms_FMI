class Solution {
public:
    bool binarySearch(vector<int>& arr, int target)
    {
        int left = 0;
        int right = arr.size() - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(arr[mid] == target)
                return true;
            if(arr[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i = 0; i < rows; i++)
        {
            if(matrix[i][0] <= target && matrix[i][cols - 1] >= target)
            {
                return binarySearch(matrix[i], target);
            }
        }
        return false;
    }
};