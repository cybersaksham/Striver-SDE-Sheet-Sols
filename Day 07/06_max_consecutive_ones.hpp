class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, tmpCount = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 1) tmpCount++;
            else tmpCount = 0;
            count = max(count, tmpCount);
        }
        return count;
    }
};