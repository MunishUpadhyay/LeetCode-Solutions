class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mpp;

        for (char c : word) {
            mpp[c]++;
        }

        vector<pair<char, int>> v(mpp.begin(), mpp.end());

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        int result = 0;
        int i = 0;

        for (auto &it : v) {
            int cost = i / 8 + 1;
            result += it.second * cost;
            i++;
        }

        return result;
    }
};