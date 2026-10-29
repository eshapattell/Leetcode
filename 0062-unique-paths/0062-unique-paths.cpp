class Solution {
public:
    int solve(int m, int n, vector<vector<int>>&dp){
        //base case
        if(m==0 && n==0){
            return 1;
        }
        //invalid
        if(m< 0 || n<0){
            return 0;
        }
        //if not -1 ie value already calc
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        //two ways possible going up and left
        int up= solve(m-1, n, dp);
        int left= solve(m, n-1, dp);

        //returning curr dp by adding both
        return dp[m][n]= up+ left; 
    }
    int uniquePaths(int m, int n) {
        //2d dp
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(m-1,n-1, dp);
    }
};

