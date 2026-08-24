class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        //how many matches each player has lost
        unordered_map<int, int> losses;

        //all players who have played at least one match
        unordered_set<int> players;

        for(int i = 0; i < matches.size(); i++) {

            // matches[i][0] is winner
            int winner = matches[i][0];

            // matches[i][1] is loser
            int loser = matches[i][1];

            // both winner and loser have participated in a match
            players.insert(winner);
            players.insert(loser);

            // increase loss count of the loser
            losses[loser]++;
        }

        // players with 0 losses
        vector<int> zeroLoss;

        // players with exactly 1 loss
        vector<int> oneLoss;

        // checking loss count of every player
        for(int player : players) {

            // if player is not present in losses map,
            // it means they never lost
            if(losses[player] == 0) {
                zeroLoss.push_back(player);
            }

            // if player lost exactly once
            else if(losses[player] == 1) {
                oneLoss.push_back(player);
            }
        }

        sort(zeroLoss.begin(), zeroLoss.end());
        sort(oneLoss.begin(), oneLoss.end());

        return {zeroLoss, oneLoss};
    }
};