class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int, int>> groups;
        for(int i = 0; i < groupSizes.size(); i++)
        {
            groups.push_back({groupSizes[i], i});
        }
        sort(groups.begin(), groups.end());

        vector<vector<int>> result;
        vector<int> current;
        for(int i = 0; i < groups.size(); i++)
        {
            current.push_back(groups[i].second);
            if(current.size() == groups[i].first)
            {
                result.push_back(current);
                current.clear();
            }
        }
        return result;
    }
};