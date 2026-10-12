class Solution{
    long long MOD = 1000000007;
public:
    int countHousePlacements(int n)
    {
        vector<int> filled(n + 1);
        vector<int> space(n + 1);
        
        filled[1] = 1;
        space[1] = 1;
        
        for (int i = 2; i <= n; i++)
        {
            filled[i] = space[i - 1];
            space[i] = (filled[i - 1] + space[i - 1]) % MOD;
        }  

        long long total = (filled[n] + space[n]) % MOD;
        long long res = (total * total) % MOD;
       
        return res;
    }
};