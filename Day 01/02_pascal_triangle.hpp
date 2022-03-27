class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i=0; i<numRows; i++) {
            vector<int> tmpVec;
            tmpVec.push_back(1);
            if(i > 0) {
                vector<int> prev = ans[i - 1];
                for(int j=0; j<prev.size()-1; j++) tmpVec.push_back(prev[j] + prev[j + 1]);
                tmpVec.push_back(1);
            }
            ans.push_back(tmpVec);
        }
        
        return ans;
    }
};