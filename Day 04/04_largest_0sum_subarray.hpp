class Solution{
    public:
    int maxLen(vector<int>&A, int n) {   
        // Your code here
        int maxLen = 0, sum = 0;
        map<int, int> m;
        m[0] = -1;
        
        for(int i=0; i<n; i++) {
            sum += A[i];
            if(m.count(sum) == 0) m[sum] = i;
            else maxLen = max(maxLen, i - m[sum]);
        }
        
        return maxLen;
    }
};