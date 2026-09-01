class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        int count = 0;
        int n = s.size();
        unordered_map<char,int> mp;

        while(r < n){
            char ch = s[r];
            mp[ch]++;

            while(mp.size() == 3){
                count += n - r;
                mp[s[l]]--;
                if(mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }
            r++;
        }

        return count;
    }
};