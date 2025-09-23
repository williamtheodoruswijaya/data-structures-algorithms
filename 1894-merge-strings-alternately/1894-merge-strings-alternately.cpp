class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";

        int length = min(word1.size(), word2.size());
        for (int i = 0; i < length; i++) {
            ans += word1[i];
            ans += word2[i];
        }

        if (word1.size() > length) {
            for (int i = length; i < word1.size(); i++) {
                ans += word1[i];
            }
        } else if (word2.size() > length) {
            for (int i = length; i < word2.size(); i++) {
                ans += word2[i];
            }
        }
        
        return ans;
    }
};