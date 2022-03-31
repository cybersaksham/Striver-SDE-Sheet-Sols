class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        
        for(int i=0; i<n; i++) {
            if(m.count(nums[i]) == 0) {
                int a = nums[i];
                if(m.count(a + 1) == 0 && m.count(a - 1) == 0) m[a] = a;
                else if(m.count(a + 1) == 0) {
                    int low = m[a - 1];
                    m[low] = a;
                    m[a] = low;
                }
                else if(m.count(a - 1) == 0) {
                    int high = m[a + 1];
                    m[high] = a;
                    m[a] = high;
                }
                else {
                    int low = m[a - 1], high = m[a + 1];
                    m[low] = high;
                    m[high] = low;
                    m[a] = high;
                }
            }
        }
        
        int maxLen = 0;
        unordered_map<int, int>::iterator it;
        for(it=m.begin(); it!=m.end(); it++) maxLen = max(maxLen, abs(it->first - it->second + 1));
        
        return maxLen;
    }
};