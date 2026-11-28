class Solution {
public:

    //function to check whether a substring is palindrome
    bool isPalindrome(string &s, int i, int j) {
        while(i <j) {
            if(s[i] != s[j])
                return false;

            i++;
            j--;
        }
        return true;
    }

    int solve(int i, string &s, vector<int> &dp) {
        int n = s.size();

        //base case
        //return -1 bcz it computes '1+' at partition so the way is 0 but if we return 0 it will still return 1
        if(i == n)
            return -1;

        if(dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;

        // try every possible ending index
        for(int j= i; j< n; j++) {
            //checking if current is palindrome or not
            if(isPalindrome(s,i,j)) {

                //make a cut and solve remaining string
                ans = min(ans, 1+ solve(j+1,s,dp));
            }
        }
        return dp[i] = ans;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);

        return solve(0, s, dp);
    }
};
