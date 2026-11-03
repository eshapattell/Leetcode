class Solution {
    long  ans = 0;

    bool isPal(string &s)
    {
        int start=0, end = s.length()-1;
        while(start < end)
        {
            if(s[start] != s[end]) return false;
            start++; end--;
        }
        return true;
    }
        void helper(string &s,int idx,string &s1,string &s2){
            if(isPal(s1) && isPal(s2)){
                long temp= (int) s1.length() * s2.length();
                ans= max(ans, temp);     
           }
            for(int i=idx;i<s.size();i++){
                s1.push_back(s[i]);
                helper(s,i+1,s1,s2);
                s1.pop_back();

                s2.push_back(s[i]);
                helper(s,i+1,s1,s2);
                s2.pop_back();
            }
           return;
        }

public:
    int maxProduct(string s) {
        string s1="";
        string s2="";
        helper(s,0,s1,s2);
        return ans;
    }
};