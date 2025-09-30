class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = INT_MIN;
        for (int pile : piles) {
            if (pile > max) max = pile;
        }

        int left = 1, right = max;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            long long int totalSum = 0;
            for (int pile : piles) {
                totalSum += ceil((double) pile / (double) mid);
            }

            if (totalSum > h) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};