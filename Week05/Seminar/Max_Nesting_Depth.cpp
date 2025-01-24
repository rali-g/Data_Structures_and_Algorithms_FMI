class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxCount = 0;
        int count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(count > maxCount)
                maxCount = count;
            if(s[i] == '(')
            {
                st.push(s[i]);
                count++;
            }
            else if(s[i] == ')')
            {
                st.pop();
                count--;
            }
        }
        return maxCount;
    }
};