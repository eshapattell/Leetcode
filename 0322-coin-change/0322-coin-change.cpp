class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 1e9;

        vector<vector<int>> dp(n, vector<int>(amount + 1, INF));

        for (int idx = 0; idx < n; idx++) {
            dp[idx][0] = 0;
        }

        for (int a = 0; a <= amount; a++) {
            if (a % coins[0] == 0) {
                dp[0][a] = a / coins[0];
            }
        }

        for (int idx = 1; idx < n; idx++) {
            for (int a = 1; a <= amount; a++) {
                int skip = dp[idx - 1][a];
                int take = INF;

                if (coins[idx] <= a) {
                    take = 1 + dp[idx][a - coins[idx]];
                }

                dp[idx][a] = min(take, skip);
            }
        }
        int ans = dp[n - 1][amount];

        return ans >= INF ? -1 : ans;
    }
};