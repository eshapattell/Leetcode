class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int idx;
        int minDist = INT_MAX;
        vector<vector<int>> mindrones;
        int n = drones.size();
        for(int i = 0; i < n ; i++){
            int distance = abs(drones[i][0] - target[0]) + 
                              abs(drones[i][1] - target[1]);
            if(distance <= drones[i][2]){
                mindrones.push_back({distance,i});
            }
        }

        if(mindrones.size() == 0){
            return -1;
        }else{
            sort(mindrones.begin(),mindrones.end());
        }
        return mindrones[0][1];
    }
};