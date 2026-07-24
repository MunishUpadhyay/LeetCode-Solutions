class Solution {
public:
    int LCS(string& a, string& b) {
        int m = a.length();
        int n = b.length();

        int t[m + 1][n + 1];

        for(int i = 0; i < m + 1; i++) {
            for(int j = 0; j < n + 1; j++) {

                if(i == 0 || j == 0)
                    t[i][j] = 0;
            }
        }

        for(int i = 1; i < m + 1; i++) {
            for(int j = 1; j < n + 1; j++) {

                if(a[i - 1] == b [j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];

                else
                    t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }

        return t[m][n];
    }

    int longestPalindromeSubseq(string s) {
        string sOriginal = s;
        reverse(s.begin(), s.end());

        return LCS(sOriginal, s);
    }
};