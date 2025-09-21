class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, left = 0, sum = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            // expand right
            sum += nums[right];

            // write down the results for the first time
            if (sum >= target) {
                int length = right - left + 1;
                ans = min(ans, length);
            }

            // shrink left to find optimal minimum
            while (sum >= target) {
                sum -= nums[left++];

                if (sum >= target) {
                    int length = right - left + 1;
                    ans = min(ans, length);
                }
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};