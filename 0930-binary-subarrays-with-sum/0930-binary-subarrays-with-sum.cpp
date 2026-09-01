class Solution {
public:
    int sumK(vector<int>& nums, int k){
        int l = 0;
        int r = 0;
        int n = nums.size();
        int sum = 0;
        int ans=0;
        if(k<0)  
        return 0;
        while(r < n){
            sum += nums[r];
            while(l<=r && sum > k){
                sum -= nums[l];
                l++;
            }
            ans += r - l + 1;
            r++;
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int m = sumK(nums,goal);
        int n = sumK(nums,goal - 1);
        return m - n;
    }
};