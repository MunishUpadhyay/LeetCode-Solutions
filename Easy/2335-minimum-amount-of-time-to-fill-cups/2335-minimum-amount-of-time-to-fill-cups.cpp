class Solution {
public:
    int fillCups(vector<int>& amount) {
        int sumOfCups = 0;
        int maxCup = 0;
        for(int i = 0; i < amount.size(); i++) {
            sumOfCups += amount[i];
            maxCup = max(maxCup, amount[i]);
        }

        return max(maxCup, (sumOfCups + 1) / 2);
    }
};