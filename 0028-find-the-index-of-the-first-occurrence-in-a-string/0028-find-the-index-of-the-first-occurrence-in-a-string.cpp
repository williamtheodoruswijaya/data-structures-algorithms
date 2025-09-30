class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = -1;
        for (int left = 0; left < haystack.size(); left++) {
            if (haystack[left] == needle[0]) {
                int right = left + 1, idx = 1;
                while (right < haystack.size() && idx < needle.size() && haystack[right] == needle[idx]) {
                    right++;
                    idx++;
                }
                if (idx == needle.size()) {
                    ans = left;
                    break;
                }
            }
        }
        return ans;
    }
};