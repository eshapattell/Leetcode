class Solution {
public:
    bool isPalindrome(string &s){
        int left = 0, right = s.size()-1;
        while(left < right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
    void generate(string &s, vector<vector<string>>&res, vector<string>subs, int currIdx){
        if(currIdx == s.size()){
            res.push_back(subs);
            return;
        }

        string sx = "";
        for(int i=currIdx; i<s.size(); i++){
            sx += s[i];
            if(isPalindrome(sx)){
                subs.push_back(sx);
                generate(s, res, subs, i+1);
                subs.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>subs;
        generate(s, res, subs, 0);
        return res;
    }
};