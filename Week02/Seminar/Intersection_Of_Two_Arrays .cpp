class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int histogram[1001] {0};
        for(int i = 0; i < nums1.size(); i++)
        {
            histogram[nums1[i]]++;
        }
        for(int i = 0; i < nums2.size(); i++)
        {
            if(histogram[nums2[i]])
            {
                result.push_back(nums2[i]);
                histogram[nums2[i]]--;
            }
        }
        return result;
    }
};