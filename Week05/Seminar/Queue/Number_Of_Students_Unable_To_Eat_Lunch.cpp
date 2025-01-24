class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int index = 0;
        int counter = 0;
        for(int i = 0; i < students.size(); i++)
        {
            q.push(students[i]);
        }
        while(!q.empty())
        {
            counter++;
            if(q.front() == sandwiches[index])
            {
                index++;
                q.pop();
                counter = 0;
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
            if(counter == sandwiches.size() - index)
            {
                return counter;
            }
        }
        return 0;
    }
};