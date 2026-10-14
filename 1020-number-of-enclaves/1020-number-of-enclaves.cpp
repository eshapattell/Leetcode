class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& grid, int row, int col) {
        if(row < 0 || col < 0 || row >= m || col >= n) return;
        if(grid[row][col] != 1) return;

        // Remove land connected to the boundary
        grid[row][col] = 0;

        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Remove all land connected to left and right boundaries
        for(int row = 0; row < m; row++){
            dfs(grid, row, 0);
            dfs(grid, row, n - 1);
        }

        // Remove all land connected to top and bottom boundaries
        for(int col = 0; col < n; col++){
            dfs(grid, 0, col);
            dfs(grid, m - 1, col);
        }

        int count = 0;

        // Count the remaining enclosed land cells
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) count++;
            }
        }

        return count;
    }
};