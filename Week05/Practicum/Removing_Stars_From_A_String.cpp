class Solution {
public:
    string removeStars(string s) {
        string res;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != '*')
            {
                res.push_back(s[i]);
                continue;
            }  
            if(!res.empty())
                res.pop_back();
        }
        return res;
    }
};