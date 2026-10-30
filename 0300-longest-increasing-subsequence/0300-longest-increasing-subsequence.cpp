class Solution {
public:
int solve(int idx, int prev, vector<int>&nums, vector<vector<int>>&dp){
    int n= nums.size();

    //reaches the end
    if(idx == n){
        return 0;
    }

    //prev+1 bcz we have initial dp from -1 so we need to do +1
    if(dp[idx][prev+1] != -1){
        return dp[idx][prev+1];
    }

    //not picked
    int skip= solve(idx+1, prev, nums, dp);
    int take=0;

    //picked if  the first element or curr greater than prev
    if(prev == -1 || nums[idx] > nums[prev]){
        take= 1 + solve(idx+1, idx, nums, dp);
    }

    return dp[idx][prev+1] = max(take, skip);
}

    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();

        //two states change idx and prev so 2d dp
        vector<vector<int>>dp(n, vector<int>(n, -1));

        return solve(0, -1,nums, dp);
    }
};

