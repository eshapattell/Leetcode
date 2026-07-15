class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int s=1,end=INT_MIN;
        int ans;
        for(int i=0;i<n;i++){
            end= max(end, nums[i]);
        }
        while(s<=end){
            int mid= s+(end-s)/2;
            int sum=0;
            for(int i=0;i<n;i++){
                sum += (nums[i]+mid -1)/mid;
            }
            if(sum <= threshold){
                ans= mid;
                end= mid-1;
            }else{
                s= mid+1;
            }
        }
        return ans;
    }
};