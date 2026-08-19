class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minFreq(26, 1000);

        for (string word : words) {
            vector<int> freq(26, 0);

            for (char ch : word) {
                freq[ch - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                minFreq[i] = min(minFreq[i], freq[i]);
            }
        }

        vector<string> ans;
        for (int i = 0; i < 26; i++) {
            while (minFreq[i] > 0) {
                string ch(1, 'a' + i);
                ans.push_back(ch);
                minFreq[i]--;
            }
        }
        return ans;
    }
};