class Solution {
public:
    int solve(string& s, int start, int end, int k) {
        if (end - start + 1 < k)
            return 0;

        vector<int> freq(26, 0);

        for (int i = start; i <= end; i++) {
            freq[s[i] - 'a']++;
        }

        for (int i = start; i <= end; i++) {

            if (freq[s[i] - 'a'] < k) {

                int left = solve(s, start, i - 1, k);
                int right = solve(s, i + 1, end, k);

                return max(left, right);
            }
        }

        return end - start + 1;
    }

    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size() - 1, k);
    }
};