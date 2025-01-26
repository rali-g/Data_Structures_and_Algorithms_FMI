class Solution {
public:
    int freeSpaceCount(vector<vector<int>>& grid, int rows, int cols, int& x, int& y)
    {
        int count = 0;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 0)
                    count++;
                if(grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                }
            }
        }
        return count;
    }
    void backtracking(vector<vector<int>>& grid, int x, int y, int rows, 
    int cols,vector<vector<bool>>& visited, int counter, int spaceCount, int& answer)
    {
        if(counter == spaceCount && grid[x][y] == 2)
        {
            answer++;
            return;
        }
        visited[x][y] = true;
        if(x + 1 < rows && !visited[x + 1][y] && grid[x + 1][y] != -1)
        {
            backtracking(grid, x + 1, y, rows, cols, visited, counter + 1, spaceCount, answer);
        }
        if(x - 1 >= 0 && !visited[x - 1][y] && grid[x - 1][y] != -1)
        {
            backtracking(grid, x - 1, y, rows, cols, visited, counter + 1, spaceCount, answer);
        }
        if(y + 1 < cols && !visited[x][y + 1] && grid[x][y + 1] != -1)
        {
            backtracking(grid, x, y + 1, rows, cols, visited, counter + 1, spaceCount, answer);
        }
        if(y - 1 >= 0 && !visited[x][y - 1] && grid[x][y - 1] != -1)
        {
            backtracking(grid, x, y - 1, rows, cols, visited, counter + 1, spaceCount, answer);
        }
        visited[x][y] = false;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int startRow = 0;
        int startCol = 0;
        int answer = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, 0));
        int spaceCount = freeSpaceCount(grid, rows, cols, startRow, startCol);
        backtracking(grid, startRow, startCol, rows, cols, visited, 0, spaceCount + 1, answer);
        return answer;
    }
};