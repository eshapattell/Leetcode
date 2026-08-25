class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if(p.size() > s.size()) {
            return ans;
        }
        unordered_map<char, int> target;
        unordered_map<char, int> window;

        for(char ch : p) {
            target[ch]++;
        }
        int left = 0;

        for(int right = 0; right < s.size(); right++) {
            window[s[right]]++;

            if(right - left + 1 > p.size()) {
                window[s[left]]--;

                if(window[s[left]] == 0) {
                    window.erase(s[left]);
                }
                left++;
            }
            
            if(right - left + 1 == p.size() &&
               window == target) {
                ans.push_back(left);
            }
        }
        return ans;
    }
};