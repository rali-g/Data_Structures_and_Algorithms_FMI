class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singles = 0;
        int doubles = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= 9)
                singles += nums[i];
            else
                doubles += nums[i];
        }
        return singles != doubles;
    }
};