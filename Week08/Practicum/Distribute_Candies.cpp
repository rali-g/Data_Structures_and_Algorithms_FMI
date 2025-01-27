class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> setty;
        int maxCandies = candyType.size() / 2;
        for(int i = 0; i < candyType.size(); i++)
        {
            setty.insert(candyType[i]);
        }
        return maxCandies < setty.size() ? maxCandies : setty.size();
    }
};