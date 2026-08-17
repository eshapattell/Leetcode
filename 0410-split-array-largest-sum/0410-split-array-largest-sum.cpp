class Solution {
public:
    bool getAns(int mid, int k , vector<int>&nums){
        //to add sum of subarray
        int sum=0;
        //to count how many ksubarray mid takes
        int totalSub=1;
        
        for(auto num: nums){
            //adding value to sum of subarray
            sum+= num;
            //if sum exceeds mid value then count of subarray inc
            if(sum > mid){
                totalSub++;
                //to make the sum start again from the current nums[i]
                sum=num;
            }
            //if for current mid it takes more than k splits then its false
            if(totalSub > k)return false;
        }
        //true
        return totalSub <=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int lo= 0;
        int high=0;
        int ans=0;

        for(int i=0;i< nums.size();i++){
            //maximum element of the array
            //k's min value can be 1 so in that case max element will be the lo
            lo = max(lo, nums[i]);
            //total sum of the array
            high += nums[i];
        }
        while(lo <= high){
            int mid = lo + (high-lo)/2;
            //if true then we will move left side as value greater than that will also be true
            if(getAns(mid, k, nums)){
                ans= mid;
                high= mid-1;
            }
            //if false we move to right bcz value less than that will also false
            else{
                lo= mid+1;
            }
        }
        return ans;
    }
};