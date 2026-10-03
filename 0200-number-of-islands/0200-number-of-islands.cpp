class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        int count = 0;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                
                // Found a new island
                if(grid[i][j] == '1') {
                    
                    count++;
                    
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    
                    // Mark as visited
                    grid[i][j] = '0';
                    
                    while(!q.empty()) {
                        
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        
                        // Check 4 directions
                        for(int k = 0; k < 4; k++) {
                            
                            int nr = r + dr[k];
                            int nc = c + dc[k];
                            
                            // Check boundaries and whether it is land
                            if(nr >= 0 && nr < rows &&
                               nc >= 0 && nc < cols &&
                               grid[nr][nc] == '1') {
                                
                                q.push({nr, nc});
                                
                                // Mark visited
                                grid[nr][nc] = '0';
                            }
                        }
                    }
                }
            }
        }
        
        return count;
    }
};