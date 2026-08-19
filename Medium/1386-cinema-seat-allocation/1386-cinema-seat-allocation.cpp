class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mpp;

        for(int i = 0; i < reservedSeats.size(); i++) {
            int row = reservedSeats[i][0];
            int col = reservedSeats[i][1] - 1;

            mpp[row] |= 1 << col;
        }

        int left   = ((1 << 4) - 1) << 1;
        int middle = ((1 << 4) - 1) << 3;
        int right  = ((1 << 4) - 1) << 5;

        int result = 0;

        for(auto &[row, mask] : mpp) {
            if((mask & left) == 0 && (mask & right) == 0)
                result += 2;
            else if((mask & left) == 0 || (mask & middle) == 0 || (mask & right) == 0)
                result += 1;
        }

        result = result + 2 * (n - mpp.size());

        return result;
    }
};