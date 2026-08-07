class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int n = directions.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            char ch = directions[i];

            if (ch == 'L') {
                if (!st.empty() && st.top() == 'R') {
                    // First R-L head-on collision: 2 collisions
                    st.pop();
                    ans += 2;
                    ch = 'S';  // resulting stationary car

                    // Any more R's behind will hit this S: +1 each
                    while (!st.empty() && st.top() == 'R') {
                        st.pop();
                        ans += 1;
                    }
                } 
                else if (!st.empty() && st.top() == 'S') {
                    // L hitting a stationary car → 1 collision, becomes S
                    ans += 1;
                    ch = 'S';
                } 
                else {
                    // Leading L moving off-road, no collision
                    continue;
                }
            } 
            else if (ch == 'S') {
                // All R's behind will collide with this S
                while (!st.empty() && st.top() == 'R') {
                    st.pop();
                    ans += 1;
                }
            }

            // Push only R or S (L is either ignored or turned into S)
            if (ch == 'R' || ch == 'S') {
                st.push(ch);
            }
        }

        return ans;
    }
};
