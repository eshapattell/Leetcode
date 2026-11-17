class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long dp[n+1][2]; // two states -> 1 or 0

        dp[n][1]=0;
        dp[n][0]=0;

        for(int idx = n-1 ; idx>=0 ; idx--){ 
            int x = nums[idx];
            dp[idx][1] = max(dp[idx+1][1] , x + dp[idx+1][0]); // flag = true // flag is isEven
            dp[idx][0] = max(dp[idx+1][0] , -x + dp[idx+1][1]); // flag = false 
        }
        return dp[0][1];
    }
};