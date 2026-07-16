class Solution {
public:
    long long gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int mx = 0;

        for(int i = 0; i < n; i++) {
            mx = max(nums[i], mx);
            prefixGcd[i] = gcd(nums[i], mx);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int l = 0;
        int r = prefixGcd.size() - 1;

        long long totalSum = 0;

        while(l < r) {
            totalSum += gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }

        return totalSum;
    }
};