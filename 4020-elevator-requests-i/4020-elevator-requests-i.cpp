class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int curr=0;
        int ans=0;

        for(auto floor: requests){
            ans+= abs(curr - floor);
            curr= floor;
        }
        return ans;
    }
};