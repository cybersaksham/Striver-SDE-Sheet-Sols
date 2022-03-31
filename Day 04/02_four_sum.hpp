class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n-1; k++) {
                    long long a = (long long)nums[i], b = (long long)nums[j], c = (long long)nums[k];
                    long long x = target - a - b - c;
                    if(binary_search(nums.begin() + k + 1, nums.end(), (int)x)) {
                        vector<int> tmp;
                        tmp.push_back((int)a);
                        tmp.push_back((int)b);
                        tmp.push_back((int)c);
                        tmp.push_back((int)x);
                        sort(tmp.begin(), tmp.end());
                        ans.insert(tmp);
                    }
                }
            }
        }
        
        vector<vector<int>> finalAns(ans.begin(), ans.end());
        return finalAns;
    }
};