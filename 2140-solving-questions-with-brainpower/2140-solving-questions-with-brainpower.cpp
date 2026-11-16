
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            //choice 1 solve current question
            int next = i + questions[i][1] + 1;

            long long solve = questions[i][0];

            if (next <= n) {
                solve += dp[next];
            }

            //choice 2 skip current question
            long long skip = dp[i + 1];

            dp[i] = max(solve, skip);
        }

        return dp[0];
    }
};
