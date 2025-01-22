class Solution {
public:
    string frequencySort(string s) {
        vector<int> counter(256, 0);
        for(int i = 0; i < s.size(); i++)
        {
            counter[s[i]]++;
        }
        vector<std::pair<int, int>> result;
        for(int i = 0; i < 256; i++)
        {
            if(counter[i] != 0)
            {
                result.push_back(std::make_pair((char)i, counter[i]));
                counter[i] = 0;
            }
        }
        std::sort(result.begin(), result.end(), [](std::pair<int, int>& p1, std::pair<int, int>& p2)
        {
            return p1.second > p2.second;
        });
        string output;
        for(int i = 0; i < result.size(); i++)
        {
            for(int j = 0; j < result[i].second; j++)
            {
                output += result[i].first;
            }
        }
        return output;
    }
};