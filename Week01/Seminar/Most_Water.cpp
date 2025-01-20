class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = INT_MIN;
        int begin = 0;
        int end = height.size() - 1;
        while(begin < end)
        {
            int currentArea = (end - begin) * std::min(height[begin], height[end]);
            maxArea = std::max(currentArea, maxArea);
            if(height[begin] < height[end])
            {
                begin++;
            }
            else
            {
                end--;
            }
        }
        return maxArea;
    }
};