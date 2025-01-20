class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        bool histogram[256]{false};
        int count = 0;
        for(int i = 0; i < jewels.size(); i++)
        {
            histogram[jewels[i]] = true;
        }
        for(int i = 0; i < stones.size(); i++)
        {
            if(histogram[stones[i]])
            {
                count++;
            }
        }
        return count;
    }
};