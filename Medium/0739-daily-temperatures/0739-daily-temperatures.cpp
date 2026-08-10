class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> result(n);

        for(int i = n - 1; i >= 0; i--) {
            if (!st.empty()) {
                while(!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                    st.pop();
                }
            }
            result[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }

        return result;
    }
};