class Solution {
public:
    struct Node{
        int x, y, removedObstacles;
        bool operator<(const Node& other) const
        {
            return removedObstacles > other.removedObstacles;
        }
    };
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<Node> nextToProcess;
        nextToProcess.push({0, 0, 0});
        vector<vector<int>> distances(n, vector<int>(m, INT_MAX));
        distances[0][0] = 0;

        while(!nextToProcess.empty())
        {
            Node current = nextToProcess.top();
            nextToProcess.pop();
            if(current.removedObstacles > distances[current.x][current.y])
                continue;
            if(current.x == n - 1 && current.y == m - 1)
                return distances[n - 1][m - 1];
            for(int i = 0; i < 4; i++)
            {
                int newX = current.x + directions[i][0];
                int newY = current.y + directions[i][1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m)
                {
                    int newWeight = current.removedObstacles + grid[newX][newY];
                    if(newWeight < distances[newX][newY])
                    {
                        distances[newX][newY] = newWeight;
                        nextToProcess.push({newX, newY, newWeight});
                    }
                }
            }
        }
        return -1;
    }
};