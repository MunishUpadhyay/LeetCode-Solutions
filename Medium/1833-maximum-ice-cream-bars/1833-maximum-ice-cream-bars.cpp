class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> freq(100001, 0);    // Max size of element is 10^5

        for(int cost : costs)
            freq[cost]++;

        int count = 0;

        for(int cost = 1; cost <= 100000; ++cost) {
            if(coins < cost)
                break;
            
            int currBuy = min(freq[cost], coins / cost);
            count += currBuy;
            coins -= currBuy * cost;
        }

        return count;
    }
};