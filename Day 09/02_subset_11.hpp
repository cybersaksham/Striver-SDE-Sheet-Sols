class Solution {
    set<vector<int>> subsets(vector<int> &nums, int N) {
        if(N == 0) {
            set<vector<int>> ans;
            vector<int> tmp;
            ans.insert(tmp);
            return ans;
        }
        set<vector<int>> ans = subsets(nums, N - 1);
        vector<vector<int>> fin(ans.begin(), ans.end());
        int k = fin.size();
        for(int i=0; i<k; i++) {
            vector<int> tmp = fin[i];
            tmp.push_back(nums[N - 1]);
            ans.insert(tmp);
        }
        return ans;
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans = subsets(nums, nums.size());
        vector<vector<int>> fin(ans.begin(), ans.end());
        return fin;
    }
};