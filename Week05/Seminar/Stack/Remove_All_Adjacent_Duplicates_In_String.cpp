class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string result;
        for(int i = 0; i < s.size(); i++)
        {
            if(!st.empty() && s[i] == st.top())
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};