class Solution {
public:
    bool isVowel(char& ch) {
        return (ch == 'a') || (ch == 'e') || (ch == 'o') || (ch == 'u') || (ch == 'i');
    }
    long long countVowels(string word) {
        long long output = 0;
        size_t n = word.size();
        for (size_t i = 0; i < word.size(); ++i) {
            if (isVowel(word[i])) output += 1LL * (i + 1) * (n - i);
        }
        return output;
    }
};