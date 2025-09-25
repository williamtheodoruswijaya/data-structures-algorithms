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
        for (int i = 0; i < 27; i++) {
            cout << "maps1: " << "[" << i << "] " << maps1[i] << endl;
            cout << "maps2: " << "[" << i << "] " << maps2[i] << endl;
            cout << "\n";
            if (maps1[i] == 0 && maps2[i] != 0 || maps1[i] != 0 && maps2[i] == 0) return false;
        }

        // step 4: count the number of occurance for each maps and check it
        sort(maps1.begin(), maps1.end());
        sort(maps2.begin(), maps2.end());
        
        return maps1 == maps2;
    }
};