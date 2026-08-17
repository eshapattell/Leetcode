class Solution {
public:
    bool getAns(long long mid, vector<int>time, long long totalTrips){
        //calculate the trips
        long long trips=0;

        for(auto t:time){
            //adding number of trips done by each bus for the curr time
            trips +=mid/t;
            //trips more, that means for the curr time totalTrips can be achieved 
            if(trips >= totalTrips){
                return true;
            }
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long lo=1;
        long long high=INT_MAX;
        long long ans=0;
        //min element
        for(int i=0;i<time.size();i++){
            high= min(high, (long long)time[i]);
        }
        //high cannot be more than min element* totalTrips
        high *= totalTrips;
        while(lo <= high){
            long long mid= lo+ (high-lo)/2;
            //true that means after curr time it will be always be true
            if(getAns(mid,time, totalTrips)){
                ans= mid;
                high= mid-1;
            }else{
                //false then before curr time obvious it will be false
                lo= mid+1;
            }
        }
        return ans;
    }
};