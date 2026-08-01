// MCM Pattern code, not optimal for large constraints
// class Solution {
//     int t[2001][2001];

// public:
//     int solve(string &s, int i, int j) {
//         if (i >= j)
//             return 0;

//         if(isPalindrome(s, i, j) == true)
//             return 0;

//         if (t[i][j] != -1)
//             return t[i][j];

//         int mn = INT_MAX;
//         int left = -1, right = -1;
        
//         for (int k = i; k < j; k++) {
//             if(t[i][k] != -1)
//                 left = t[i][k];
//             else {
//                 t[i][k] = solve(s, i, k);
//                 left = t[i][k];
//             }

//             if(t[k + 1][j] != -1)
//                 right = t[k + 1][j];

//             else {
//                 t[k + 1][j] = solve(s, k + 1, j);
//                 right = t[k + 1][j];
//             }

//             int temp = 1 + left + right;
//             mn = min(mn, temp);
//         }

//         return t[i][j] = mn;
//     }

//     bool isPalindrome(string &s, int i, int j) {
//         if(i >= j) return true;

//         while(i < j) {
//             if(s[i] != s[j]) {
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }

//     int minCut(string s) {
//         memset(t, -1, sizeof(t));
//         return solve(s, 0, s.length() - 1);
//     }
// };

class Solution {
    int t[2001];
    bool pal[2001][2001];

public:
    void buildPalindrome(string &s) {
        int n = s.size();

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (len == 1)
                    pal[i][j] = true;
                else if (len == 2)
                    pal[i][j] = (s[i] == s[j]);
                else
                    pal[i][j] = (s[i] == s[j] && pal[i + 1][j - 1]);
            }
        }
    }

    int solve(string &s, int i) {
        int n = s.size();

        if (i == n)
            return -1;   // No cut needed after the last partition

        if (t[i] != -1)
            return t[i];

        int ans = INT_MAX;

        for (int j = i; j < n; j++) {
            if (pal[i][j]) {
                ans = min(ans, 1 + solve(s, j + 1));
            }
        }

        return t[i] = ans;
    }

    int minCut(string s) {
        memset(t, -1, sizeof(t));
        buildPalindrome(s);
        return solve(s, 0);
    }
};