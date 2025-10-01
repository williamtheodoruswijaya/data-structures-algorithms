class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int> maps;

        string temp = "";
        for (string email : emails) {
            // Email checking
            for (int i = 0; i < email.size(); i++) {
                if (email[i] == '.') continue;
                else if (email[i] == '@') {
                    temp += email[i];

                    int idx = i + 1;
                    while (idx < email.size() && idx < email.size() - 4) {
                        temp += email[idx];
                        idx++;
                    }
                    temp += ".com";
                    break;
                } else if (email[i] == '+') {
                    while (email[i] != '@') i++;
                    while (i < email.size()) {
                        temp += email[i];
                        i++;
                    }
                } else {
                    temp += email[i];
                }
            }
            
            // Email insertion into a hashmap
            maps[temp]++;
            temp.clear();
        }

        for (auto value : maps) {
            cout << value.first << " : " << value.second << endl;
        }

        return maps.size();
    }
};