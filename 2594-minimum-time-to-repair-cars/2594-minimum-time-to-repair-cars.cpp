class Solution {
public:

    bool isPossible(vector<int>& ranks, int cars, long long time)
    {
        long long carsDone = 0;

        for(int i : ranks){
            carsDone += sqrt(time /i);
        }

        return carsDone >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long  s = 1;
        long  e = LONG_LONG_MAX;
        long ans=0;

        while(s <= e){
            long long time = s + (e - s)/2;

            if(isPossible(ranks,cars,time)){
                ans= time;
                e = time - 1;
            }else{
                s = time + 1;
            }
        }

        return ans;
    }
};