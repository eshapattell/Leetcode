class Solution {
public:
    int minOperations(string s) {
        int n= s.size();
        int ans= INT_MAX;

        for(int k=0;k<n;k++){
            string t= s.substr(k)+ s.substr(0,k);

            int operations= k;

            int i=0;
            int j= n-1;

            while(i< j){
                int a= t[i]- 'a';
                int b= t[j]- 'a';

                int diff= abs(a-b);
                operations += min(diff, 26- diff);

                i++;
                j--;
            }
            ans = min(ans, operations);
        }
        return ans;
    }
};