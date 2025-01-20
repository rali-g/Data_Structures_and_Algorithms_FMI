class Solution { //boyer-moore
public:
    int majorityElement(vector<int>& nums) {
        int votes = 0;
        int candidate = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(votes == 0)
            {
                candidate = nums[i];
                votes++;
            }
            else
            {
                if(nums[i] == candidate)
                    votes++;
                else
                    votes--;
            }
        }
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == candidate)
            {
                count++;
            } 
        }
        if(count > std::floor(nums.size() / 2))
            return candidate;
        return -1;
    }
};