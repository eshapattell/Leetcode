class Solution {
public:

    int countPairs(vector<int>& nums, int mid) {

        int count = 0;
        int left = 0;

        for(int right = 0; right < nums.size(); right++) {

            while(nums[right] - nums[left] > mid) {
                left++;
            }

            count += right - left;
        }

        return count;
    }

    int smallestDistancePair(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.back() - nums.front();

        while(low < high) {

            int mid = low + (high - low) / 2;

            int count = countPairs(nums, mid);

            if(count >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};