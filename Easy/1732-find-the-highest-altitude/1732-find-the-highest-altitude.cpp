class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        // ----> Brute Force

        // vector<int> altitude(n + 1, 0);

        // int sum = 0;

        // for(int i = 1; i <= n; i++) {
        //     sum += gain[i - 1];
        //     altitude[i] = sum;
        // }

        // int highestAltitude = INT_MIN;

        // for(int i = 0; i <= n; i++) {
        //     highestAltitude = max(highestAltitude, altitude[i]);
        // }

        // return highestAltitude;

        int highestAltitude = 0;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += gain[i];
            highestAltitude = max(highestAltitude, sum);
        }

        return highestAltitude;
    }
};