class Solution {
public:
    bool closeStrings(string word1, string word2) {

        // step 1: ensure both word1 and word2 have the same length
        if (word1.size() != word2.size()) return false;

        // step 2: get maps for each word
        vector<int> maps1(27, 0);
        vector<int> maps2(27, 0);
        for (char ch : word1) maps1[ch - 'a']++;
        for (char ch : word2) maps2[ch - 'a']++;

        // step 3: compare for each alfabet between maps
        multiset<int> set1, set2;
        for (int i = 0; i < 27; i++) {
            if (maps1[i] == 0 && maps2[i] != 0 || maps1[i] != 0 && maps2[i] == 0) return false;
            else {
                set1.insert(maps1[i]);
                set2.insert(maps2[i]);
            }
        }
        
        return set1 == set2;
    }
};