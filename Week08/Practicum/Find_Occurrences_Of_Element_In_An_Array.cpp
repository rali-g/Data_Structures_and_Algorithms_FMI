class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int, int> mappy;
        int freq = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == x)
            {
                mappy[freq++] = i;
            }
        }
        vector<int> result(queries.size(), -1);
        for(int i = 0; i < queries.size(); i++)
        {
            if(mappy.count(queries[i]))
            {
                result[i] = mappy[queries[i]];
            }
        }
        return result;
    }
};