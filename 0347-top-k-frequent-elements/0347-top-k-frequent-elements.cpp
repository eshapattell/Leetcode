class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // Count frequency
        for(int num : nums) {
            mp[num]++;
        }

        // bucket[i] contains numbers appearing i times
        vector<vector<int>> bucket(nums.size() + 1);

        for(auto it : mp) {
            int num = it.first;
            int freq = it.second;

            bucket[freq].push_back(num);
        }

        vector<int> ans;

        // Start from highest frequency
        for(int i = nums.size(); i >= 1 && ans.size() < k; i--) {

            for(int num : bucket[i]) {
                ans.push_back(num);

                if(ans.size() == k) {
                    break;
                }
            }
        }

        return ans;
    }
};