class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size = 0;

        // Step 1: Find decoded length
        for (char ch : s) {
            if (isalpha(ch)) {
                size++;
            } 
            else {
                int digit = ch - '0';
                size *= digit;
            }
        }

        // Step 2: Traverse backwards
        for (int i = s.size() - 1; i >= 0; i--) {

            k %= size;

            if (k == 0 && isalpha(s[i])) {
                return string(1, s[i]);
            }

            if (isdigit(s[i])) {
                int digit = s[i] - '0';
                size /= digit;
            } 
            else {
                size--;
            }
        }

        return "";
    }
};