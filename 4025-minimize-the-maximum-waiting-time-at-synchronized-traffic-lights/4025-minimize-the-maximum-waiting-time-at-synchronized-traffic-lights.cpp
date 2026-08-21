class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int penalty = 0;
        sort(lights.begin(),lights.end());

        for(int i = 0; i < arrivalTime.size(); i++){
            int r = arrivalTime[i] % period;
            if(r >= lights[lights.size() - 1]){
                penalty = max(penalty,period - r);
            }
        }

        return penalty;
    }
};