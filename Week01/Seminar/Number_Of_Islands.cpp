class Solution {
public:
    void backtracking(int x, int y, vector<vector<bool>>& visited, vector<vector<char>>& grid, 
    int rows, int cols)
    {
        if(grid[x][y] == 0)
            return;
            
        visited[x][y] = true;
        if(x + 1 < rows && !visited[x + 1][y] && grid[x + 1][y] == '1')
        {
            backtracking(x + 1, y, visited, grid, rows, cols);
        }
        if(x - 1 >= 0 && !visited[x - 1][y] && grid[x - 1][y] == '1')
        {
            backtracking(x - 1, y, visited, grid, rows, cols);
        }
        if(y + 1 < cols && !visited[x][y + 1] && grid[x][y + 1] == '1')
        {
            backtracking(x, y + 1, visited, grid, rows, cols);
        }
        if(y - 1 >= 0 && !visited[x][y - 1] && grid[x][y - 1] == '1')
        {
            backtracking(x, y - 1, visited, grid, rows, cols);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, 0));

        int islands = 0;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    backtracking(i, j, visited, grid, rows, cols);
                    islands++;
                }
            }
        }
        return islands;
    }
};