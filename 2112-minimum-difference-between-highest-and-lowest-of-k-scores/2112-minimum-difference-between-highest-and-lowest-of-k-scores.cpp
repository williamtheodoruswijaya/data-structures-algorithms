class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int left = 0, right = k - 1, ans = 1e9;
        while (right < nums.size()) {
            ans = min(ans, nums[right] - nums[left]);
            
            left++;
            right++;
        }
        return ans;
    }
};