class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        //storing in map
        for(auto x: s){
            mp[x]++;
        }
        //removing from map
        for(auto x:t){
            mp[x]--;
        }
        //if values of map is 0 that means true
        for(auto x: mp){
            if(x.second !=0){
                return false;
            }
        }
        return true;
    }
};