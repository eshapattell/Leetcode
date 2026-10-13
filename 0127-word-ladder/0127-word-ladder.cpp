class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<bool> visited(n, false);

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        for (int i = 0; i < n; i++) {
            if (wordList[i] == beginWord) {
                visited[i] = true;
            }
        }

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord) {
                return steps;
            }

            for(int i=0;i<n;i++){
                if(visited[i])continue;

                int diff=0;
                for(int j=0;j<word.size();j++){
                    if(word[j] !=wordList[i][j]){
                        diff++;
                    }
                }
                if(diff==1){
                    visited[i]=true;
                    q.push({wordList[i], steps + 1});
                }
            }
        }
        return 0;
    }
};

