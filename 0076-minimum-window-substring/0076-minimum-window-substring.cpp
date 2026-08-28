class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>mp;
        int m=s.size();
        int n= t.size();
        int count=n;

        for(auto &ch: t){
            mp[ch]++;
        }
        int minLen = INT_MAX;
        int stIndex = -1;

        for(int i=0,j=0;j < m;j++){
            mp[s[j]]--;
            if(mp[s[j]]>=0){
                count--;
            }
            
            while(count==0 && i<=j){
                if(j- i+1 < minLen){
                    minLen= j- i+1;
                    stIndex= i;
                }
                mp[s[i]]++;
                if(mp[s[i]] >0)count++;
                i++;
            }
        }
        if(stIndex==-1){
            return "";
        }
        return s.substr(stIndex, minLen);
    }
};