class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeroCount = 0;
        int maxLen = 0;

        for(int i = 0, j = 0; j < n; j++) {

            // expand window
            if(nums[j] == 0) {
                zeroCount++;
            }
            // window is invalid if zeros become more than k
            while(zeroCount > k) {
                if(nums[i] == 0) {
                    zeroCount--;
                }
                i++;
            }
            // current window has at most k zeros
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};