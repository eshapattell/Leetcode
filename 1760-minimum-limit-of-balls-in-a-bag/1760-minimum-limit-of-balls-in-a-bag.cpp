class Solution {
public:
bool check(vector<int>& nums, int maxOperations,int mid){
    int operations= 0;
    for(auto i : nums){
        operations +=(i -1)/ mid;
        if(operations > maxOperations){
            return false;
        }
    }
    return true;
}
    int minimumSize(vector<int>& nums, int maxOperations) {
        int s=1;
        int e= INT_MIN;
        for(int i=0;i<nums.size();i++){
            e= max(e, nums[i]);
        }
        while(s<=e){
            int mid= s+(e-s)/2;
            if(check(nums, maxOperations, mid)){
                e= mid-1;
            }else{
                s= mid+1;
            }
        }
        return s;
    }
};
