class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<unsigned long long>> dp(
            n + 1, vector<unsigned long long>(amount + 1, 0)
        );

        // Base case: amount 0 has exactly 1 way
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Reverse tabulation
        for (int i = n - 1; i >= 0; i--) {
            for (int a = 1; a <= amount; a++) {

                unsigned long long take = 0;

                if (coins[i] <= a) {
                    take = dp[i][a - coins[i]];
                }

                unsigned long long notTake = dp[i + 1][a];

                dp[i][a] = take + notTake;
            }
        }

        return dp[0][amount];
    }
};