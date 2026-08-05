class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n);
        ans[n -1] = 0;
        st.push(n - 1);

        for(int i = n - 2; i >= 0; i--) {
            int val = 0;
            while(!st.empty() && heights[i] >= heights[st.top()]) {
                val++;
                st.pop();
            }
            
            if (!st.empty())
                val++;

            ans[i] = val;
            st.push(i);
        }

        return ans;
    }
};