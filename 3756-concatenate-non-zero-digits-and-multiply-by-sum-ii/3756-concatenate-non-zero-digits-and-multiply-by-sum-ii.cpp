class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        // // Brute Force Approach
        // vector<int> prefixSum;
        // int add = 0;

        // for(int i = 0; i < s.length(); i++) {
        //     add += s[i] - '0';
        //     prefixSum.push_back(add);
        // }

        // vector<int> result;
        // long long x = 0, sum = 0;
        // long long ans = 0;
        // const int MOD = 1e9 + 7;

        // for(int i = 0; i < queries.size(); i++) {
        //     for(int j = queries[i][0]; j <= queries[i][1]; j++) {
        //         if(s[j] != '0') {
        //             int digit = s[j] - '0';
        //             x = (x * 10 + digit) % MOD;
        //         }
        //     }
        //     if(queries[i][0] != 0 && 
        //         prefixSum[queries[i][0]] == prefixSum[queries[i][0] - 1]) {
            
        //         sum += prefixSum[queries[i][1]] - prefixSum[queries[i][0]];
        //     }

        //     else if(queries[i][0] != 0 && 
        //             prefixSum[queries[i][0]] != prefixSum[queries[i][0] - 1]) {
                
        //         sum += prefixSum[queries[i][1]] - prefixSum[queries[i][0] - 1];
        //     }

        //     else {
        //         sum += prefixSum[queries[i][1]];
        //     }

        //     ans = x * sum;
        //     x = 0, sum = 0;
        //     result.push_back(ans % MOD);
        // }
        // return result;

        // Optimal Approach

        const long long MOD = 1000000007;

        // Store non-zero digits and their positions
        vector<int> positions;
        vector<int> digits;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                positions.push_back(i);
                digits.push_back(s[i] - '0');
            }
        }

        int n = digits.size();

        // Prefix sum of digits
        vector<long long> prefixSum(n + 1, 0);

        // Prefix value of concatenated number modulo MOD
        vector<long long> prefixNum(n + 1, 0);

        // Powers of 10 modulo MOD
        vector<long long> pow10(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + digits[i];
            prefixNum[i + 1] = (prefixNum[i] * 10 + digits[i]) % MOD;
        }

        vector<int> answer;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int L = lower_bound(positions.begin(), positions.end(), l) - positions.begin();
            int R = upper_bound(positions.begin(), positions.end(), r) - positions.begin() - 1;

            // No non-zero digits in this range
            if (L > R) {
                answer.push_back(0);
                continue;
            }

            // Sum of digits
            long long sum = prefixSum[R + 1] - prefixSum[L];

            // Number formed by non-zero digits
            int len = R - L + 1;
            long long number =
                (prefixNum[R + 1] -
                 (prefixNum[L] * pow10[len]) % MOD +
                 MOD) % MOD;

            answer.push_back((number * (sum % MOD)) % MOD);
        }

        return answer;
    }
};