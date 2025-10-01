class Solution {
public:
    int arrangeCoins(int n) {
        if (n == 1) return n;

        int left = 1, right = n;
        while (left <= right) {
            long long int mid = left + (right - left) / 2;
            
            long long int totalSum = (mid * (mid + 1)) / 2;
            
            if (totalSum == n) {
                return mid;
            } else if (totalSum > n) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }
};