class Solution {
public:
    // long long gcd(int a, int b) {
    //     if(b == 0) return a;
    //     return gcd(b, a % b);
    // }

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        // --> Brute Force Approach

        // int n = nums.size();
        // int m = queries.size();

        // vector<int> gcdPairs;

        // for(int i = 0; i < n - 1; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         gcdPairs.push_back(gcd(nums[i], nums[j]));
        //     }
        // }

        // sort(gcdPairs.begin(), gcdPairs.end());

        // vector<int> answer(m);
        // for(int i = 0; i < m; i++) {
        //     answer[i] = gcdPairs[queries[i]];
        // }

        // return answer;

        // --> Optimal Aapproach using Inclusion-Exclusion + PrefixSum + Binary Search
        // Time complexity: O(M log M + Q log M)

        long long int mx = *max_element(nums.begin(), nums.end());

        vector<int> mpp(mx + 1, 0);

        for (auto it : nums) {
            mpp[it]++;
        }

        vector<long long> cnt(mx + 1, 0);

        for (int i = mx; i >= 1; i--) {
            long long curr = 0;

            for (int k = i; k <= mx; k += i) {
                curr += mpp[k]; // inclusion of all possible pairs
            }

            cnt[i] = curr * (curr - 1) / 2;

            for (int k = 2 * i; k <= mx; k += i) {
                cnt[i] -= cnt[k]; // exclusion of all pairs covered by greater gcd
            }
        }

        for (int i = 1; i <= mx; i++) {
            cnt[i] += cnt[i - 1];
        }

        vector<int> answer;

        for (auto it : queries) {
            answer.push_back(lower_bound(cnt.begin(), cnt.end(), it + 1) - cnt.begin());
        }

        return answer;
    }
};