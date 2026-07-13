class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        solve(0, s, result, path);
        return result;
    }

    void solve(int index, string& s, vector<vector<string>>& result, vector<string>& path) {
        if(index == s.size()) {
            result.push_back(path);
            return;
        }

        for(int i = index; i < s.size(); i++) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                solve(i + 1, s, result, path);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int l, int r) {
        while(l <= r) {
            if(s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};