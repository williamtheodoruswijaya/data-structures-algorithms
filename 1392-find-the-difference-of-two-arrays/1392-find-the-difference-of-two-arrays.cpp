class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> sets1, sets2;
        for (int num : nums1) sets1.insert(num);
        for (int num : nums2) sets2.insert(num);

        for (int num : nums1) {
            if (sets2.find(num) != sets2.end() && sets1.find(num) != sets1.end()) {
                sets1.erase(num);
                sets2.erase(num);
            }
        }

        vector<vector<int>> res;
        vector<int> temp1;
        for (int num : sets1) temp1.push_back(num);
        res.push_back(temp1);

        vector<int> temp2;
        for (int num : sets2) temp2.push_back(num);
        res.push_back(temp2);
        
        return res;
    }
};