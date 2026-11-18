class Solution {
int n, k, lim;
private:
    int fnc(int ind, long long prod, int sum, int prev, int taken, vector<int> &arr, unordered_map<string, int> &mp){
        if(ind >= n){
            if(taken && sum == k && prod <= lim) return prod;
            return -1;
        }

        string key = to_string(ind) + to_string(prod) + to_string(sum) + to_string(prev) + to_string(taken);

        if(mp.count(key)) return mp[key];

        int ntake = fnc(ind+1, prod, sum, prev, taken, arr, mp);
        int take = fnc(ind+1, (prod * arr[ind]) > lim ? lim+1 : prod * arr[ind], prev ? sum + arr[ind] : sum - arr[ind], !prev, 1, arr, mp);
        return mp[key] = max(take, ntake);
    }
public:
    int maxProduct(vector<int>& nums, int k, int limit) {
        this->n = nums.size();
        this->k = k;
        this->lim = limit;
        int sum = 0;
        for(auto it: nums) sum += it;
        if(sum < abs(k)) return -1;
        unordered_map<string, int> mp;
        int ans = fnc(0, 1LL, 0, 1, 0, nums, mp);
        return ans;
    }
};