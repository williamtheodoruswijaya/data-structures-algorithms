class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, left = 0;
        unordered_set<char> strs;
        for (int right = 0; right < s.size(); right++) {
            // keep shrinking until
            while (strs.find(s[right]) != strs.end()) {
                strs.erase(s[left++]);
            }
            int length = right - left + 1;
            ans = max(ans, length);
            strs.insert(s[right]);
        }
        return ans;
    }
};