class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;

        int left = 0, sum = 0;
        for (int right = 0; right < nums.size(); right++) {
            
            // shrink left if length > k
            if (right - left + 1 > k) {
                sum -= nums[left];
                left++;
            }

            // get average when right - left + 1 == k
            sum += nums[right];
            if (right - left + 1 == k) {
                double average = sum / (double) k;
                ans = max(ans, average);
            }
        }

        return ans;
    }
};