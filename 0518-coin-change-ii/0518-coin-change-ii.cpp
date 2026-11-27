class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<unsigned long long> dp(amount + 1, 0);

        // Base case: amount 0 has exactly 1 way
        dp[0] = 1;

        // Tabulation
        for (int i = 0; i < coins.size(); i++) {
            for (int a = coins[i]; a <= amount; a++) {

                dp[a] = dp[a] + dp[a - coins[i]];
            }
        }

        return dp[amount];
    }
};