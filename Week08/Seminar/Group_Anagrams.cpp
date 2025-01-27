class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mappy;
        for(auto& iter : strs)
        {
            string word = iter;
            std::sort(word.begin(), word.end());
            mappy[word].push_back(iter);
        }
        
        vector<vector<string>> result;
        for(auto& iter : mappy)
        {
            result.push_back(iter.second);
        }
        return result;
    }
};