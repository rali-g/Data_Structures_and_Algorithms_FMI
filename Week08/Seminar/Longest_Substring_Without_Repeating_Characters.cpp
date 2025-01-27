class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin = 0;
        int end = 0;
        int maxLength = 0;
        unordered_set<char> setty;
        while(end < s.size())
        {
            if(setty.count(s[end]))
            {
                while(s[begin] != s[end])
                {
                    setty.erase(s[begin]);
                    begin++;  
                }
                begin++;
            }
            else
            {
                setty.insert(s[end]);                
            }
            maxLength = std::max(maxLength, end - begin + 1);
            end++;
        }
        return maxLength;
    }
};