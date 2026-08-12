class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int ans = 0;

        unordered_map<int, int> mpp;

        while(right < nums.size()) {
            mpp[nums[right]]++;

            while(mpp[nums[right]] > k) {
                mpp[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};