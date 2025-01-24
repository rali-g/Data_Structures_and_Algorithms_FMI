class Solution {
public:
    bool isOpposite(char ch)
    {
        return ch == '(' || ch == '{' || ch == '[';
    }
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++)
        {
            if(isOpposite(s[i]))
                st.push(s[i]);
            else
            {
                if(st.empty())
                    return false;
                if(st.top() == '(' && s[i] == ')')
                {
                    st.pop();
                }
                else if(st.top() == '{' && s[i] == '}')
                {
                    st.pop();
                }
                else if(st.top() == '[' && s[i] == ']')
                {
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};