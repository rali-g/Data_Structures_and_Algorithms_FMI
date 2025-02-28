class Solution {
public:
    struct Node{
        int x, y;
        int value;
        bool operator<(const Node& other) const{
            return value > other.value;
        }
    };
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int minimumEffortPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> distances(rows, vector<int>(cols, INT_MAX));
        distances[0][0] = 0;
        priority_queue<Node> nextToProcess;
        nextToProcess.push({0, 0, 0});
        while(!nextToProcess.empty())
        {
            Node current = nextToProcess.top();
            nextToProcess.pop();
            if(current.value > distances[current.x][current.y])
                continue;
            if(current.x == rows - 1 && current.y == cols - 1)
                return distances[rows - 1][cols - 1];
            for(int i = 0; i < 4; i++)
            {
                int newX = current.x + directions[i][0];
                int newY = current.y + directions[i][1];
                if(newX < rows && newY < cols && newX >= 0 && newY >= 0)
                {
                    int newWeight = max(abs(grid[newX][newY] - grid[current.x][current.y]), 
                    distances[current.x][current.y]);
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