class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,-1);
        
        dp[0]=nums[0];
        if(n==1){
            return dp[0];
        }
        
        dp[1]= max(dp[0], nums[1]);

        for(int idx=2;idx<n;idx++){
            int take = dp[idx - 2] + nums[idx];
            int skip = dp[idx - 1];

            dp[idx] = max(take, skip); 
        }
        return dp[n-1];
    }
};






        