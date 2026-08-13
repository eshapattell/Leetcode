class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int>ans; 
        //adding into map
        for(auto x: nums){
            mp[x]++;
        }
        //traversing the map
        for(auto [key,value]: mp){
            if(value == 2){
                ans.push_back(key);
            }
        }
        //return vector
        return ans;
    }
};