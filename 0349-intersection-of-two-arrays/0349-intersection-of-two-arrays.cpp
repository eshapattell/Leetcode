class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto num: nums1){
            mp[num]++;
        }
        for(auto num: nums2){
            if(mp[num]){
                ans.push_back(num);
                mp[num]=0;
            }
        }
        return ans;
    }
};