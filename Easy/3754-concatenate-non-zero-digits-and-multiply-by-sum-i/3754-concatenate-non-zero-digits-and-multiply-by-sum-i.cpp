class Solution {
public:
    long long sumAndMultiply(int n) {
        int i = 0;
        long long x = 0;
        long long sum = 0;

        while(n > 0) {
            int digit = n % 10;
            sum += digit;

            if(digit != 0) {
                int num = pow(10, i) * digit;
                i++;
                x += num;
            }
            n /= 10;
        }

        return x * sum;
    }
};