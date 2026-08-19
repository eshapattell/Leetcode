class Solution {
public:
    bool check(vector<int>& nums1, vector<int>& nums2, int len) {
        set<vector<int>> st;

        for (int i = 0; i + len <= nums1.size(); i++) {
            vector<int> temp;

            for (int j = i; j < i + len; j++) {
                temp.push_back(nums1[j]);
            }
            st.insert(temp);
        }

        for (int i = 0; i + len <= nums2.size(); i++) {
            vector<int> temp;

            for (int j = i; j < i + len; j++) {
                temp.push_back(nums2[j]);
            }

            if (st.find(temp) != st.end()) {
                return true;
            }
        }
        return false;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int low = 0;
        int high = min(nums1.size(), nums2.size());

        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(nums1, nums2, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};