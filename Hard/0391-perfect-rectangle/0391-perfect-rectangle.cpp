class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> m;

        long long totalArea = 0;

        int minX = INT_MAX;
        int minY = INT_MAX;
        int maxX = INT_MIN;
        int maxY = INT_MIN;

        for (auto it : rectangles) {
            int x = it[0];
            int y = it[1];
            int a = it[2];
            int b = it[3];

            // Area
            totalArea += (long long)(a - x) * (b - y);

            // Bounding rectangle
            minX = min(minX, x);
            minY = min(minY, y);
            maxX = max(maxX, a);
            maxY = max(maxY, b);

            // Corner balance
            m[{x, y}]++;
            m[{a, b}]++;
            m[{x, b}]--;
            m[{a, y}]--;
        }

        // Area check
        long long boundingArea =
            (long long)(maxX - minX) * (maxY - minY);

        if (totalArea != boundingArea)
            return false;

        // Corner check
        int cnt = 0;

        for (auto it : m) {
            if (abs(it.second) == 1) {
                cnt++;

                // Must be one of the 4 outer corners
                int x = it.first.first;
                int y = it.first.second;

                if (!((x == minX || x == maxX) &&
                      (y == minY || y == maxY))) {
                    return false;
                }
            }
            else if (it.second != 0) {
                return false;
            }
        }

        return cnt == 4;
    }
};