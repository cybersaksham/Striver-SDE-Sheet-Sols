class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        if(n <= 2) return ans;
        
        for(int i=0; i<n-2; i++) {
            if(i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int start = i + 1;
                int end = n - 1;
                
                while(start < end) {
                    if(nums[i] + nums[start] + nums[end] == 0) {
                        ans.push_back({nums[i], nums[start], nums[end]});
                        while(start < end && nums[start] == nums[start + 1]) start++;
                        while(start < end && nums[end] == nums[end - 1]) end--;
                        start++;
                        end--;
                    }
                    else if(nums[i] + nums[start] + nums[end] > 0) end--;
                    else start++;
                }
            }
        }
        
        return ans;
    }
};