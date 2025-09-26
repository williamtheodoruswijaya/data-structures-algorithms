class Solution {
public:
    int compress(vector<char>& chars) {
        // s-cases:
        if (chars.size() == 1) return 1;

        // base-cases:
        string ans = "";
        int left = 0, count = 0;
        chars.push_back(',');
        for (int right = 1; right < chars.size(); right++) {
            if (chars[left] == chars[right]) {
                count++;
            } else {
                if (count != 0) {
                    ans += chars[left];
                    ans += to_string(count+1);
                } else {
                    ans += chars[left];
                }
                count = 0;
            }
            left = right;
        }
        
        chars.clear();
        for (int i = 0; i < ans.size(); i++) {
            chars.push_back(ans[i]);
        }

        return ans.size();
    }
};