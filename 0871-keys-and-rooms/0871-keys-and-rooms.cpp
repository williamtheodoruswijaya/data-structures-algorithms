class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> st;
        set<int> visited;

        int res = 0;
        st.push(0);
        visited.insert(0);

        while (!st.empty()) {
            int idx = st.top();
            st.pop();
            for (int room : rooms[idx]) {
                if (visited.insert(room).second) {
                    res++;
                    st.push(room);
                }
            }
        }
        return res + 1 == rooms.size();
    }
};