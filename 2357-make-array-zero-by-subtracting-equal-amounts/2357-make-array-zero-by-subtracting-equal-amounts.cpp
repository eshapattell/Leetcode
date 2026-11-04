class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)pq.push(nums[i]);
        }
        while(!pq.empty())
        {
            ans++;
            int x = pq.top();
            pq.pop();
            vector<int>t;
            while(!pq.empty())
            {
                t.push_back(pq.top()-x);
                pq.pop();
            }
            for(int i=0;i<t.size();i++)
            {
                if(t[i]!=0)pq.push(t[i]);
            }
        }
        return ans;
    }
};