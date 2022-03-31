class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int fl = nums.size() / 3;
        int loopEnd = nums.size() - fl;
        vector<int> ans;
        int i = 0;
        
        while(i < loopEnd) {
            if(nums[i] == nums[i + fl]) {
                ans.push_back(nums[i]);
                i += (fl + 1);
                while(i < loopEnd && nums[i] == ans[ans.size() - 1]) i++;
            }
            else i++;
        }
        
        return ans;
    }
};