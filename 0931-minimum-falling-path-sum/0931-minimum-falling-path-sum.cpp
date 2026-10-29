class Solution {
public:
    int solve(int i, int j,vector<vector<int>>& matrix, vector<vector<int>>&dp){
        int n= matrix.size();

        // invalid column
        if(j< 0 || j >= n){
            return INT_MAX/2;
        }

        // last row can't go further
        if(i == n-1){
            return matrix[i][j];
        }
        if(dp[i][j] != -200){
            return dp[i][j];
        }

        // can go down, diagonally left, or diagonally right
        int down = solve(i + 1, j, matrix, dp);
        int left = solve(i + 1, j - 1, matrix, dp);
        int right = solve(i + 1, j + 1, matrix, dp);

        return dp[i][j]= matrix[i][j] + min({down, left, right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n =matrix.size();
        int ans=INT_MAX;
        vector<vector<int>>dp(n, vector<int>(n, -200));

        for (int j = 0; j < n; j++) {
            ans = min(ans, solve(0, j, matrix,dp));
        }
        return ans;
    }
};
