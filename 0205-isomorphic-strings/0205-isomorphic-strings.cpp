class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int>mp;
        unordered_map<char,int>mp2;

        for(int i=0;i<s.size();i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]]=i;
            }
            if(mp2.find(t[i]) == mp2.end()){
                mp2[t[i]]=i;
            }
            if(mp[s[i]] != mp2[t[i]]){
                return false;
            }
        }
        return true;
    }
};