class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, left = 0;
        unordered_set<char> strs;
        for (int right = 0; right < s.size(); right++) {
            // shrink only if
            if (strs.find(s[right]) != strs.end()) {
                left += 1;
                right = left;
                strs.clear();
            }
            int length = right - left + 1;
            ans = max(ans, length);
            strs.insert(s[right]);
        }
        return ans;
    }
};