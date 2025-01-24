class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> s;
        int n = tokens.size();
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            if(tokens[i] == "+")
            {
                result = s.top();
                s.pop();
                result += s.top();
                s.pop();
                s.push(result);
            }
            else if(tokens[i] == "-")
            {
                result = s.top();
                s.pop();
                result -= s.top();
                s.pop();
                s.push(-result);
            }
            else if(tokens[i] == "*")
            {
                result = s.top();
                s.pop();
                result *= s.top();
                s.pop();
                s.push(result);
            }
            else if(tokens[i] == "/")
            {
                int temp = s.top();
                s.pop();
                result = s.top() / temp;
                s.pop();
                s.push(result);
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};