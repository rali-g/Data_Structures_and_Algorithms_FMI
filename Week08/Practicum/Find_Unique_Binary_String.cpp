class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string diagonal;
        for(int i = 0; i < nums.size(); i++)
        {
            diagonal += (nums[i][i] == '0' ? '1' : '0');
        }
        return diagonal;
    }
};