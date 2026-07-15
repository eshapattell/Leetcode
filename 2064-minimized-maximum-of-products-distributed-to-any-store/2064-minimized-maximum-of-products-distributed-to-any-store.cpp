class Solution {
public:
bool getAns(vector<int>& quantities, int n,int mid){
    int sum=0;
    for(int i=0;i<quantities.size();i++){
        sum += (quantities[i]+mid -1)/mid;
    }
    return sum <= n;
}
    int minimizedMaximum(int n, vector<int>& quantities) {
        int s= 1;
        int end=INT_MIN;
        int ans;
        for(int i=0;i<quantities.size();i++){
            end= max(end, quantities[i]);
        }
        while(s<=end){
            int mid= s+(end-s)/2;
            if(getAns(quantities,n,mid)){
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