class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;

        //iterate through the magazine and count characters
        for (char c : magazine) {
            if (mp.find(c) == mp.end()) {
                mp[c] = 1;
            } else {
                mp[c]++;
            }
        }

        //iterate through the ransom note and check character counts
        for (char c : ransomNote) {
            if (mp.find(c) != mp.end() && mp[c] > 0) {
                mp[c]--;
            } else {
                return false;
            }
        }

        return true;
    }
};