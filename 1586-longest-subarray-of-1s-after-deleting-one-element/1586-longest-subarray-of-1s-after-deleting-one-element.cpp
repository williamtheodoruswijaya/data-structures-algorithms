class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, ans = INT_MIN, countOne = 0;
        for (int right = 0; right < nums.size(); right++) {
            // expand
            if (nums[right] == 1) countOne++;

            // shrink
            while (left < right && right - left + 1 - countOne > 1) {
                if (nums[left] == 1) countOne--;
                left++;
            }

            // update length
            int length = right - left;
            ans = max(ans, length);
        }
        return ans;
    }
};