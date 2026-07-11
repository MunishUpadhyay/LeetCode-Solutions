class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int sum = a + b + c;
        int maxi = max({a, b, c});

        return min(sum - maxi, sum / 2);
    }
};