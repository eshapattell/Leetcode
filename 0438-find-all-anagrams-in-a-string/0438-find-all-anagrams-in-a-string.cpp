class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if(p.size() > s.size()) {
            return ans;
        }
        unordered_map<char, int> target;
        unordered_map<char, int> window;

        // count frequency of every character in p
        for(char ch : p) {
            target[ch]++;
        }

        // left pointer of sliding window
        int left = 0;

        // right pointer moves through the string
        for(int right = 0; right < s.size(); right++) {

            // add current character to the window
            window[s[right]]++;

            // if window becomes bigger than p,
            // remove character from the left side
            if(right - left + 1 > p.size()) {

                // decrease frequency of left character
                window[s[left]]--;

                // if its frequency becomes 0,
                // completely remove it from the map
                if(window[s[left]] == 0) {
                    window.erase(s[left]);
                }

                // move left pointer forward
                left++;
            }

            // now window size is equal to p.size()
            // if both frequency maps are same,
            // current substring is an anagram of p
            if(right - left + 1 == p.size() &&
               window == target) {
                ans.push_back(left);
            }
        }
        return ans;
    }
};