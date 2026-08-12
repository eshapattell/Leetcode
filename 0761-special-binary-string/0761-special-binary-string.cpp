class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int balance = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                balance++;
            else
                balance--;

            // Found a complete special substring
            if (balance == 0) {

                // Remove outer 1 and 0
                string inner = s.substr(start + 1, i - start - 1);

                // Recursively maximize inner part
                inner = makeLargestSpecial(inner);

                // Put outer 1 and 0 back
                parts.push_back("1" + inner + "0");
                start = i + 1;
            }
        }

        // Sort largest strings first
        sort(parts.rbegin(), parts.rend());

        // Combine everything
        string result;
        for (string part : parts) {
            result += part;
        }
        return result;
    }
};