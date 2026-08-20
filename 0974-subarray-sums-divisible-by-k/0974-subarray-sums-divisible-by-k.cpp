class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int prefixSum = 0;
        int count = 0;

        // remainder 0 already exists once
        // because prefix sum before starting is 0
        mp[0] = 1;

        for (int num : nums) {
            prefixSum += num;

            int remainder = prefixSum % k;

            // C++ can give negative remainder
            if (remainder < 0) {
                remainder += k;
            }

            // If same remainder appeared before,
            // those positions form valid subarrays
            count += mp[remainder];

            mp[remainder]++;
        }

        return count;
    }
};