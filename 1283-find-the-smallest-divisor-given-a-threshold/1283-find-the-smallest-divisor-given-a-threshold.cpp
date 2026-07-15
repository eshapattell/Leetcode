class Solution {
public:
bool getAns(vector<int>& nums, int threshold,int mid){
    int n= nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum += (nums[i]+mid -1)/mid;
    }
    return sum <= threshold;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s= 1;
        int end=INT_MIN;
        int ans;
        for(int i=0;i<nums.size();i++){
            end= max(end, nums[i]);
        }
        while(s<=end){
            int mid= s+(end-s)/2;
            if(getAns(nums,threshold,mid)){
                ans= mid;
                end=mid-1;
            }
            else{
                s= mid+1;
            }
        }
        return ans;
    }
};