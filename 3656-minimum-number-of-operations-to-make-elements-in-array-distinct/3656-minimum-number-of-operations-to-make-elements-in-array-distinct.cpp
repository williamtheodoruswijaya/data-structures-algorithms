class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> sets;
        
        double ans = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (sets.find(nums[i]) != sets.end()) {
                ans = (double) (i + 1) / 3;
                break;
            }
            sets.insert(nums[i]);
        }

        return (int)ceil(ans);
    }
};