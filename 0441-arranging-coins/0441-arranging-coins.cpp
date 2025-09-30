class Solution {
public:
    int arrangeCoins(int n) {
        if (n == 1) return n;
        
        int left = 0, right = n - 1;
        while (left <= right) {
            long long int mid = left + (right - left) / 2;
            long long int sum = (mid * (mid + 1)) / 2;
            if (sum < n) {
                left = mid + 1;
            } else if (sum > n) {
                right = mid - 1;
            } else {
                return mid;
            }
        }

        return right;
    }
};