class Solution {
public:
    //We only need to check for substrings of minSize

    //Since any valid longer substring contains a valid shorter one (becuz unique letters stay <= maxLetters)
    //Checking only minSize suffices for the maximum frequency

    //If longer one occurs x times
    //it's substring must occur >= x times

    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        
        int f[26] = {0};
        int letters = 0;

        unordered_map<string, int> mp;
        
        for(int i = 0; i < minSize; i++){
            if(!f[s[i]-'a']) letters += 1;
            f[s[i]-'a'] += 1;
        }

        //initial window (0 start)
        if(letters <= maxLetters){
            string sub = s.substr(0, minSize);
            mp[sub] += 1;
        }

        //subsequent windows
        for(int i = 1; i+minSize-1 < s.length(); i++){
            //remove left most char from window
            int c = s[i-1] - 'a';
            f[c]--;
            if (!f[c]) letters--;

            //add the char to the right of the window
            c = s[i+minSize-1] - 'a';
            if (!f[c]) letters++;
            f[c]++;

            //check condition
            if (letters <= maxLetters) {
                string sub = s.substr(i, minSize);
                mp[sub] += 1;
            }

        }

        auto max_it = max_element(
            mp.begin(), mp.end(), [](const auto& p1, const auto& p2) {
                return p1.second < p2.second; // Compare the second elements
            });
        return mp.size() ? max_it->second : 0;
    }
};