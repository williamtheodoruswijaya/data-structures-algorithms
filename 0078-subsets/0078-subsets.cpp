class Solution {
public:
    vector<vector<int>> res;

    void dfs(int idx, vector<int>& nums, vector<int>& temp) {
        if (idx == nums.size()) {
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        dfs(idx+1, nums, temp);

        temp.pop_back();
        dfs(idx+1, nums, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        dfs(0, nums, temp);
        return res;
    }
};