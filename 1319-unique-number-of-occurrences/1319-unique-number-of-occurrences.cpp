class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> maps;
        for (int num : arr) {
            maps[num]++;
        }

        unordered_set<int> sets;
        for (auto value : maps) {
            if (sets.find(value.second) != sets.end()) return false;
            sets.insert(value.second);
        }

        return true;
    }
};