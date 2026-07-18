class Solution {
public:
int gcd(int a,int b){
    while(b != 0){
        int rem= a%b;
        a=b;
        b=rem;
    }
    return a;
}
    int findGCD(vector<int>& nums) {
        int minNo = INT_MAX;
        int maxNo = INT_MIN;
        for(int i=0;i< nums.size();i++){
            minNo = min(minNo, nums[i]);
            maxNo = max(maxNo, nums[i]);
        }
        return gcd(minNo, maxNo);
    }
};