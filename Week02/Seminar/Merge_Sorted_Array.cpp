class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end = nums1.size() - 1;
        --m; --n;
        for(int i = nums1.size() - 1; i >= 0; i--)
        {
            if(m < 0)
            {
                nums1[end--] = nums2[n--];
            }
            else if(n < 0)
            {
                nums1[end--] = nums1[m--];
            }
            else if(nums1[m] > nums2[n])
            {
                nums1[end--] = nums1[m--];
            }
            else
            {
                nums1[end--] = nums2[n--];
            }
        }       
    }
};