class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = 0;
        int maxPoints = 0;
        int currPoints = 0;
        while(l < k){
            currPoints += cardPoints[l++];
        }

        l = k - 1;
        maxPoints = currPoints;

        int n= cardPoints.size();

        for(int r = cardPoints.size() - 1; r >= (n- k); r--){
            currPoints -= cardPoints[l--];
            currPoints += cardPoints[r];
            maxPoints = max(currPoints, maxPoints);
        }

        return maxPoints;
    }
};