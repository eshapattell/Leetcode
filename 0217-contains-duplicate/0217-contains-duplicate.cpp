class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        //add into map
        for(auto x: nums){
            mp[x]++;
            //if two directly return true 
            if(mp[x] == 2){
                return true;
            }
        }
        
        return false;
    }
};