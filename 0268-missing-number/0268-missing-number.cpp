class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> sets;
        
        for (int i = 1; i <= nums.size(); i++) {
            sets.insert(i);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (sets.find(nums[i]) != sets.end()) {
                sets.erase(nums[i]);
            }
        }

        int ans = 0;
        for (int elm : sets) {
            ans = elm;
            break;
        }

        return ans;
    }
};