class Solution {
public:
    struct Node{
        string str;
        int count;
        bool operator<(const Node& other) const
        {
            return count > other.count || (count == other.count && str > other.str);
        }
    };
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<string> result;

        queue<int> q; //bfs
        unordered_map<string, int> frequency;
        unordered_map<int, unordered_set<int>> graph;
        unordered_set<int> visited;
        priority_queue<Node> pq;
        for(int i = 0; i < friends.size(); i++)
        {
            for(int j = 0; j < friends[i].size(); j++)
            {
                graph[i].insert(friends[i][j]);
                graph[friends[i][j]].insert(i);
            }
        }
        q.push(id);
        visited.insert(id);
        int count = 1;
        while(!q.empty())
        {
            int size = q.size();
            //cout << size << endl;
            for(int i = 0; i < size; i++)
            {
                int current = q.front();
                q.pop();
                for(auto& neighbor : graph[current])
                {
                    if(!visited.count(neighbor))
                    {
                        q.push(neighbor);
                        visited.insert(neighbor);
                        //cout << current << " " << count << endl;
                        if(count == level)
                        {
                            for(int j = 0; j < watchedVideos[neighbor].size(); j++)
                            {
                                frequency[watchedVideos[neighbor][j]]++;
                            }
                        }  
                    }
                }
            }
            count++;
        }  
        for(auto& curr : frequency)
        {
            pq.push({curr.first, curr.second});
        }
        while(!pq.empty())
        {
            result.push_back(pq.top().str);
            pq.pop();
        }
        return result;
    }
};