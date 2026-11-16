
class Solution {
public:
    long long solve(int i, vector<vector<int>>& questions,
                    vector<long long>& dp) {

        int n = questions.size();

        //base case
        if (i >= n) {
            return 0;
        }

        //already calculated
        if (dp[i] != -1) {
            return dp[i];
        }

        //choice 1 solve current question
        long long solveChoice = questions[i][0] +
            solve(i + questions[i][1] + 1, questions, dp);

        //choice 2 skip current question
        long long skipChoice = solve(i + 1, questions, dp);

        return dp[i] = max(solveChoice, skipChoice);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        vector<long long> dp(n, -1);

        return solve(0, questions, dp);
    }
};
