class Solution {
public:
    void getBfs(vector<vector<char>>& grid, int i, int j,vector<vector<int>>& visited){
        int rows= grid.size();
        int cols= grid[0].size();

        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        queue<pair<int, int>> q;

        q.push({i, j});
        visited[i][j] = 1;

        while(!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                // Check boundary
                if(nr >= 0 && nr < rows &&
                   nc >= 0 && nc < cols) {

                    // Check if land and not visited
                    if(grid[nr][nc] == '1' &&
                       visited[nr][nc] == 0) {

                        visited[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
                
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows= grid.size();
        int cols= grid[0].size();
        
        int count=0;

        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        //traversing grid
        for(int i=0;i<rows;i++){
            for(int j=0;j< cols;j++){
                if(grid[i][j]=='1' && visited[i][j] == 0){

                    getBfs(grid, i, j, visited);
                    count++;
                }
            }
        }
        return count;
    }
};