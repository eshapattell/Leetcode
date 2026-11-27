class Solution {
public:
    int solve(int i, int amount,vector<int>& coins,vector<vector<int>>& dp) {

        if (amount ==0) return 1;

        if (i ==0) {
            return amount % coins[0] == 0;
        }

        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }

        int take= 0;
        if (coins[i] <= amount) {
            take = solve(i, amount -coins[i], coins, dp);
        }

        int notTake = solve(i -1, amount, coins, dp);

        return dp[i][amount]= take+ notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n =coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        return solve(n -1, amount, coins, dp);
    }
};