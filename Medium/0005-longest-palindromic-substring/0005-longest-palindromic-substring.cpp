class Solution {
public:

    // --> The below function is correct for Longest Palindromic Subsequence

    // string printLCS(string &a, string &b) {
    //     int m = a.length();
    //     int n = b.length();

    //     int t[m + 1][n + 1];

    //     for(int i = 0; i < m + 1; i++) {
    //         for(int j = 0; j < n + 1; j++) {

    //             if(i == 0 || j == 0)
    //                 t[i][j] = 0;
    //         }
    //     }

    //     for(int i = 1; i < m + 1; i++) {
    //         for(int j = 1; j < n + 1; j++) {

    //             if(a[i - 1] == b[j - 1]) 
    //                 t[i][j] = 1 + t[i - 1][j - 1];

    //             else
    //                 t[i][j] = 0;
    //         }
    //     }

    //     int i = m, j = n;
    //     string res = "";

    //     while(i > 0 && j > 0) {
    //         if(a[i - 1] == b[j - 1]) {
    //             res.push_back(a[i - 1]);
    //             i--;
    //             j--;
    //         }

    //         else {
    //             if(t[i][j - 1] > t[i - 1][j]) 
    //                 j--;

    //             else
    //                 i--;
    //         }
    //     }

    //     return res; 
    // }
    int start = 0;
    int maxLength = 1;

    void expand(string &s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {

            int currentLength = right - left + 1;

            if(currentLength > maxLength) {
                maxLength = currentLength;
                start = left;
            }

            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {
        int n = s.size();

        if(n <= 1)
            return s;

        for(int i = 0; i < n; i++) {

            // Odd length palindrome
            expand(s, i, i);

            // Even length palindrome
            expand(s, i, i + 1);
        }

        return s.substr(start, maxLength);
    }
};