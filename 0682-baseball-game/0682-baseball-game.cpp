class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;

        int ans = 0, top = 0;
        for (int i = 0; i < operations.size(); i++) {
            if (i && operations[i] == "+") {
                int sum = record[top-1] + record[top-2];
                record.push_back(sum);
                top++;
            } else if (i && operations[i] == "D") {
                int twice = record[top-1] * 2;
                record.push_back(twice);
                top++;
            } else if (i && operations[i] == "C") {
                record.pop_back();
                top--;
            } else {
                record.push_back(stoi(operations[i]));
                top++;
            }
        }

        for (int num : record) {
            ans += num;
        }

        return ans;
    }
};