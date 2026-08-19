class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet;

        for (string word : banned) {
            bannedSet.insert(word);
        }
        unordered_map<string, int> freq;

        string word = "";
        string ans = "";
        int maxFreq = 0;

        //extra space helps process the last word
        paragraph += " ";

        for (char ch : paragraph) {

            if (isalpha(ch)) {
                word += tolower(ch);
            }
            else {
                if (!word.empty()) {

                    if (bannedSet.find(word) == bannedSet.end()) {
                        freq[word]++;

                        if (freq[word] > maxFreq) {
                            maxFreq = freq[word];
                            ans = word;
                        }
                    }
                    word = "";
                }
            }
        }
        return ans;
    }
};