class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for(char ch : s) {
            freq[ch]++;
        }

        //store character and its frequency together
        vector<pair<char, int>> arr;

        //copy data from map into vector
        for(auto it : freq) {
            arr.push_back({it.first, it.second});
        }

        //sort characters according to frequency
        //higher frequency should come first
        sort(arr.begin(), arr.end(),
             [](pair<char, int> a, pair<char, int> b) {
                 return a.second > b.second;
             });

        string ans = "";

        // add every character according to its frequency
        for(auto it : arr) {

            char ch = it.first;
            int count = it.second;

            // if character appears count times,
            // add it count times into answer
            while(count--) {
                ans += ch;
            }
        }
        return ans;
    }
};