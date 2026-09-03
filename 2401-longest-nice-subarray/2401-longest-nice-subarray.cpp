class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        int l = 0, r = 0, tmp = 0;
        while(r < n) {
            while(tmp & nums[r]) tmp ^= nums[l++];
            tmp |= nums[r++];
            ans = max(ans, r-l);
        }
        return ans;
    }
};