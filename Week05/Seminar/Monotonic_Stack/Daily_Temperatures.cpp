class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> mStack;
        for(int i = 0; i  < temperatures.size(); i++)
        {
            while(!mStack.empty() && temperatures[mStack.top()] < temperatures[i])
            {
                result[mStack.top()] = i - mStack.top();
                mStack.pop();
            }
            mStack.push(i);
        }
        return result;
    }
};