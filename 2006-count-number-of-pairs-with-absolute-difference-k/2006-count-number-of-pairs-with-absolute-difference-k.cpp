class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count=0;

        for(int i=0;i<nums.size();i++){
            auto it1 = mp.find(nums[i] - k);
            auto it2 = mp.find(nums[i] +k);
            if(it1 != mp.end()){
                count+= mp[nums[i]-k];
            }
            if(it2 != mp.end()){
                count+= mp[nums[i]+k];
            }     
            mp[nums[i]]++;      
        }
        return count;
    }
};