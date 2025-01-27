class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int maxFreq = 0;
        int maxLen = 0;
        unordered_map<int, int> freqCount; //freq --> numbers with that freq
        unordered_map<int, int> numFreq;

        for(int i = 0; i < nums.size(); i++)
        {
            int &freq = numFreq[nums[i]]; //reference binding to numFreq directly
            if(freqCount.count(freq))
            {
                freqCount[freq]--;
            }
            freqCount[++freq]++;
            maxFreq = std::max(maxFreq, freq);

            if(maxFreq == 1 || freqCount[1] == 1 && freqCount[maxFreq] * maxFreq + 1 == i + 1
            || freqCount[maxFreq] == 1 && freqCount[maxFreq - 1] * (maxFreq - 1) + maxFreq == i + 1)
            {
                maxLen = i + 1;
            } 
        }
        return maxLen;
    }
};