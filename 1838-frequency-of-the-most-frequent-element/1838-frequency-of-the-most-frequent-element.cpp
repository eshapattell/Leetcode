class Solution {
public:
    bool check(vector<int>& nums, int k, int len) {
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (i >= len) {
                sum -= nums[i - len];
            }

            if (i >= len - 1) {
                long long target = nums[i];
                long long cost = target * len - sum;

                if (cost <= k) {
                    return true;
                }
            }
        }
        return false;
    }

    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int low = 1;
        int high = nums.size();
        int ans = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(nums, k, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};