class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>&dp, vector<vector<bool>>& vis) {
        int n = triangle.size();

        //last row cant go further so we return
        if (i == n - 1) {
            return triangle[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if (vis[i][j]) {
            return dp[i][j];
        }
        
        //can go only two ways down and i+1 
        int down = solve(i + 1, j, triangle, dp,vis);
        int diagonal = solve(i + 1, j + 1, triangle, dp, vis);

        vis[i][j]= true;
        //returning the min of down and diag and adding the curr value
        return dp[i][j]= triangle[i][j] + min(down, diagonal);
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();

        vector<vector<int>>dp(n, vector<int>(n, -1));
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        return solve(0, 0, triangle, dp, vis);
    }
};

