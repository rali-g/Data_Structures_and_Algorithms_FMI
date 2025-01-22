class Solution {
public:
    void merge(vector<std::pair<int, int>>& arr, int left, int right, int mid, vector<int>& count) {
        vector<std::pair<int, int>> result(right - left);
        int leftIndex = left;
        int rightIndex = mid;
        int currentIndex = 0;

        int rightCount = 0;

        while (leftIndex < mid && rightIndex < right) {
            if (arr[rightIndex].first >= arr[leftIndex].first) {
                count[arr[leftIndex].second] += rightCount;
                result[currentIndex++] = arr[leftIndex++];
            } 
            else {
                rightCount++;
                result[currentIndex++] = arr[rightIndex++];
            }
        }

        while (leftIndex < mid) {
            count[arr[leftIndex].second] += rightCount;
            result[currentIndex++] = arr[leftIndex++];
        }

        while (rightIndex < right) {
            result[currentIndex++] = arr[rightIndex++];
        }

        for (int i = 0; i < result.size(); i++) {
            arr[left + i] = result[i];
        }
    }

    void mergeSort(vector<pair<int, int>>& arr, vector<int>& count, int left, int right) {
        if (right - left <= 1) {
            return;
        }
        int mid = left + (right - left) / 2;

        mergeSort(arr, count, left, mid);
        mergeSort(arr, count, mid, right);

        merge(arr, left, right, mid, count);
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        vector<pair<int, int>> arr;

        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }
        mergeSort(arr, count, 0, nums.size());
        return count;
    }
};
