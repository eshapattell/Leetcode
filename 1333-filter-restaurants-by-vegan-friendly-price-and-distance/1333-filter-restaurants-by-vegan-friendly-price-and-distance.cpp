class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants,int veganFriendly,int maxPrice,int maxDistance) {

        vector<vector<int>> valid;

        // Filter
        for(auto restaurant : restaurants) {

            if(veganFriendly == 1 &&
               restaurant[2] != 1) {
                continue;
            }

            if(restaurant[3] > maxPrice) {
                continue;
            }

            if(restaurant[4] > maxDistance) {
                continue;
            }

            valid.push_back(restaurant);
        }

        // Sort
        sort(valid.begin(), valid.end(),
            [](const vector<int>& a, const vector<int>& b) {

                // Higher rating first
                if(a[1] != b[1]) {
                    return a[1] > b[1];
                }

                // Higher ID first
                return a[0] > b[0];
            });

        // Store IDs
        vector<int> ans;

        for(auto restaurant : valid) {
            ans.push_back(restaurant[0]);
        }

        return ans;
    }
};