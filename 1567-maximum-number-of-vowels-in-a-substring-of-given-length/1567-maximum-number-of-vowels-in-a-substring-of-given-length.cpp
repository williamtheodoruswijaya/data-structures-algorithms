class Solution {
public:
    bool isVowel(char ch) {
        switch (ch) {
            case 'a':
                return true;
            case 'i':
                return true;
            case 'u':
                return true;
            case 'e':
                return true;
            case 'o':
                return true;
            default:
                return false;
        }
    }

    int maxVowels(string s, int k) {
        int left = 0, ans = 0, countVowel = 0;

        // expand window and check for the first window
        for (int right = 0; right < k; right++) {
            if (isVowel(s[right])) countVowel++;
            ans = max(ans, countVowel);
        }

        for (int right = k; right < s.size(); right++) {
            // shrink window
            if (right - left + 1 > k) {
                if (isVowel(s[left])) countVowel--;
                left++;
            }

            // add right to maps for each expansions
            if (isVowel(s[right])) countVowel++;

            // update ans
            ans = max(ans, countVowel);
        }

        return ans;
    }
};