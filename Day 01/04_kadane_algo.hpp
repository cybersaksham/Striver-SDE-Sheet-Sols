class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if(currSum >= 0) currSum += nums[i];
            else currSum = nums[i];
            maxSum = max(currSum, maxSum);
        }
        
        return maxSum;
    }
};