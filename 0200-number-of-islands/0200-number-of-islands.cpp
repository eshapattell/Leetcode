class Solution {
public:
    void getAns(vector<vector<char>>& grid, int r, int c){
        int rows= grid.size();
        int cols= grid[0].size();

        //if out of bound or not an island
        if(r <0 || c<0 || r >= rows || c >= cols || grid[r][c]== '0'){
            return;
        }

        grid[r][c]='0';
        //traversing all 4 sides
        getAns(grid, r+1,c);
        getAns(grid, r-1,c);
        getAns(grid, r,c+1);
        getAns(grid, r,c-1);
                
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows= grid.size();
        int cols= grid[0].size();

        int islands=0;

        //traversing grid
        for(int i=0;i<rows;i++){
            for(int j=0;j< cols;j++){
                if(grid[i][j]=='1'){
                    islands++;

                    getAns(grid, i, j);
                }
            }
        }
        return islands;
    }
};