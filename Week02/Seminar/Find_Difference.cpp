class Solution {
public:
    char findTheDifference(string s, string t) {
        int histogram[26]{0};
        for(int i = 0; i < s.size(); i++)
        {
            histogram[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++)
        {
            if(histogram[t[i] - 'a'])
            {
                histogram[t[i] - 'a']--;
                continue;
            }
            return t[i];
        }
        return 0;
    }
};