class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N) {
        // Write Your Code here
        if(N == 0) {
            vector<int> ans;
            ans.push_back(0);
            return ans;
        }
        vector<int> ans = subsetSums(arr, N - 1);
        int k = ans.size();
        for(int i=0; i<k; i++) ans.push_back(ans[i] + arr[N - 1]);
        return ans;
    }
};