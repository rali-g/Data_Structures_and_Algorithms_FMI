class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(int i = 0; i < operations.size(); i++)
        {
            if(operations[i] == "C")
            {   
                if(!s.empty())
                {
                    s.pop();
                }
            }
            else if(operations[i] == "D")
            {   
                if(!s.empty())
                {
                    int result = s.top() * 2;
                    s.push(result);
                }
            }
            else if(operations[i] == "+")
            {    
                if(s.size() >= 2)
                {
                    int last = s.top();
                    s.pop();
                    int result = last + s.top();
                    s.push(last);
                    s.push(result);
                }
            }
            else
            {
                s.push(stoi(operations[i]));
            }
        }
        int result = 0;
        while(!s.empty())
        {
            result += s.top();
            s.pop();
        }
        return result;
    }
};