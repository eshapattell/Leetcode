class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, i = 0, ans = 0;
        unordered_map<int,int>m;

        for(int j = 0; j < n; j++){
            sum += nums[j];

            if(m.count(nums[j]) && m[nums[j]] >= i){
                while(i <= m[nums[j]]){
                    sum -= nums[i];
                    i++;
                }
                m[nums[j]] = j;
            }
            m[nums[j]] = j;
            ans = max(ans, sum);
        }
        return ans;
    }
};