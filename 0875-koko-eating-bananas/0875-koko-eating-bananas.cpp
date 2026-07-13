class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1, e= INT_MAX;
        int ans= -1;
        while(s<=e){
            int rate = s+ (e-s)/2;
            long totalHours=0;
            for(int i=0; i< piles.size();i++){
                totalHours +=ceil(piles[i]/(double)rate);
            }
            if(totalHours <=h){
                ans= rate;
                e= rate-1;
            }else s= rate +1;
        }
        return ans;
    }
};