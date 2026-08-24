class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int oddCount = 0;
        int count = 0;
        mp[0] = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 != 0) {
                oddCount++;
            }

            if(mp.find(oddCount - k) != mp.end()) {
                count += mp[oddCount - k];
            }
            mp[oddCount]++;
        }
        return count;
    }
};