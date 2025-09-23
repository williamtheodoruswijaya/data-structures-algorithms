class Solution {
public:
    int findMax(unordered_map<char, int> maps) {
        int max = INT_MIN;
        for (auto &value : maps) {
            if (value.second > max) {
                max = value.second;
            }
        }
        return max;
    }

    int characterReplacement(string s, int k) {
        unordered_map<char, int> maps;
        int left = 0, ans = 0;
        for (int right = 0; right < s.size(); right++) {
            // step 1: add maps
            maps[s[right]]++;

            // step 2: find max freq
            int maxFreq = findMax(maps);

            // step 3: check if window is valid (if not shrink)
            while (left < right && right - left + 1 - maxFreq > k) {
                maps[s[left]]--;
                left++;
            }

            // step 4: update ans to the max length
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};