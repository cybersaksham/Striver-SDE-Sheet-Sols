class Solution {
    static bool compare(vector<int> v1, vector<int> v2){
        return v1[0] < v2[0];
    }
    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), this->compare);
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        for(int i=1; i<n; i++) {
            if(intervals[i][0] <= ans[ans.size() - 1][1]) ans[ans.size() - 1][1] = max(intervals[i][1], ans[ans.size() - 1][1]);
            else ans.push_back(intervals[i]);
        }
        
        return ans;
    }
};