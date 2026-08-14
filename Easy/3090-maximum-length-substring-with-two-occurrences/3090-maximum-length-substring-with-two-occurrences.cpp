class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        int right = 0;
        int ans = 0;

        unordered_map<char, int> mpp;

        while(right < s.length()) {
            mpp[s[right]]++;

            while(mpp[s[right]] > 2) {
                mpp[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};