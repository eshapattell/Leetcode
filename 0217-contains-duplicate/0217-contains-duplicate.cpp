class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        //add into map
        for(auto x: nums){
            mp[x]++;
        }
        //traverse map
        for(auto [f,s]: mp){
            if(s >1){
                return true;
            }
        }
        return false;
    }
};