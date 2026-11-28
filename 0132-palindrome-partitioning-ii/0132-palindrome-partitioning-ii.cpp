class Solution {
public:

    int minCut(string s) {
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, false));

        //step 1- precompute palindromes
        for(int i =n -1; i>= 0; i--) {
            for(int j =i; j <n; j++) {

                if(s[i] == s[j]) {
                    if(j -i <= 1)
                        pal[i][j] = true;

                    else
                        pal[i][j] = pal[i+1][j-1];
                }
            }
        }

        //step 2 minimum cuts
        vector<int> dp(n +1, INT_MAX);

        dp[n] = -1;

        for(int i =n - 1; i>= 0; i--) {
            for(int j =i; j <n; j++) {

                if(pal[i][j]) {
                    dp[i] = min(dp[i], 1+ dp[j +1]);
                }
            }
        }
        return dp[0];
    }
};
