class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0], currentMax = 0;
        int minSum = nums[0], currentMin = 0;
        int totalSum = 0;

        for(int i = 0; i < nums.size(); i++) {

            // Kadane's for maximum subarray
            currentMax = max(currentMax + nums[i], nums[i]);
            maxSum = max(maxSum, currentMax);

            // Kadane's for minimum subarray
            currentMin = min(currentMin + nums[i], nums[i]);
            minSum = min(minSum, currentMin);

            totalSum += nums[i];
        }

        // If all elements are negative, maxSum is the answer
        // (totalSum - minSum would give 0, which is an empty subarray)

        if(totalSum - minSum == 0)
            return maxSum;      // Least minimum

        return max(maxSum, totalSum - minSum);
    }
};