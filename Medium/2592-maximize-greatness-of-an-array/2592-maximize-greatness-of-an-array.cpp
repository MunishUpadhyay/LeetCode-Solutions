class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 1;
        int maxGreatness = 0;

        while(right < nums.size()) {
            if(nums[left] == nums[right])
                right++;
            
            else if(nums[left] < nums[right]) {                
                maxGreatness++;
                left++;
                right++;
            }
        }

        return maxGreatness;
    }
};