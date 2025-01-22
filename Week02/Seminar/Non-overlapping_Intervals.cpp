class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), 
        [](const vector<int>& first, const vector<int>& second)
        {
            return first[1] < second[1];
        });
        int lastNonOverlapped = intervals[0][1];
        int result = 0;
        for(int i = 1; i < intervals.size(); i++)
        {
            if(lastNonOverlapped > intervals[i][0])
            {
                result++;
            }
            else
            {
                lastNonOverlapped = intervals[i][1];
            }
        }
        return result;
    }
};