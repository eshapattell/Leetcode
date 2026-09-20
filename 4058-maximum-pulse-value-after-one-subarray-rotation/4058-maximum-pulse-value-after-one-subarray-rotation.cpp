class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();

        // ans: Running prefix pulse (alternating sum)
        // maxi: Maximum achievable gain (P[l-1] - P[r])
        // maxo: Maximum prefix pulse seen at odd indices (or -1 for the empty prefix)
        // maxe: Maximum prefix pulse seen at even indices
        long long ans = 0, maxi = 0, maxo = 0, maxe = -1e15;
        
        for(int i = 0; i < n; ++i) {
            if(i & 1) { // Current index is odd
                ans -= nums[i];
                // Max gain ending at this odd index relies on a previous odd index
                maxi = max(maxi, maxo - ans);
                // Update the maximum prefix pulse for odd indices
                maxo = max(maxo, ans);
            } else { // Current index is even
                ans += nums[i];
                // Max gain ending at this even index relies on a previous even index
                maxi = max(maxi, maxe - ans);
                // Update the maximum prefix pulse for even indices
                maxe = max(maxe, ans);
            }
        }
        
        // Return original total pulse + (2 * optimal subarray change)
        return ans + 2 * maxi;
    }
};