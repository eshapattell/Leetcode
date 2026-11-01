
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();

        vector<int> vis(n, 0);
        vector<int> need(n, 0);

        // Mark all positions belonging to non-trivial cycles
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            int j = i;
            int mn = i, mx = i;
            int len = 0;

            while (!vis[j]) {
                vis[j] = 1;
                len++;

                mn = min(mn, j);
                mx = max(mx, j);

                j = nums[j] - 1;
            }

            if (len > 1) {
                for (int x = mn; x <= mx; x++) {
                    need[x] = 1;
                }
            }
        }

        // Already unlocked positions must also be considered
        for (int i = 0; i < n; i++) {
            if (locked[i] == 0) {
                need[i] = 1;
            }
        }

        int unlock = 0;
        int swaps = 0;

        // Find continuous segments of unlocked positions
        int i = 0;

        while (i < n) {
            if (need[i] == 0) {
                i++;
                continue;
            }

            int l = i;

            while (i < n && need[i] == 1) {
                if (locked[i] == 1) {
                    unlock++;
                }
                i++;
            }

            int r = i - 1;

            // Count inversions in this segment
            for (int a = l; a <= r; a++) {
                for (int b = a + 1; b <= r; b++) {
                    if (nums[a] > nums[b]) {
                        swaps++;
                    }
                }
            }
        }

        if (unlock > k) return -1;

        return unlock + swaps;
    }
};
