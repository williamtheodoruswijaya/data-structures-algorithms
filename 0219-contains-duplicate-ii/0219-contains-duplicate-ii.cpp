class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> maps;
        
        for (int right = 0; right < nums.size(); right++) {
            if (maps.find(nums[right]) != maps.end()) {
                int diff = abs(maps[nums[right]] - right);
                if (diff <= k) {
                    return true;
                } else {
                    maps[nums[right]] = right;
                }
            } else {
                maps[nums[right]] = right;
            }
        }

        return false;
    }
};