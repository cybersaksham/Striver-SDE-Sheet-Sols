class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, count = 0, n = s.size();
        int startInd = 0;
        map<char, int> m;
        
        for(int i=0; i<n; i++) {
            if(m.count(s[i]) == 0) {
                m[s[i]] = i;
                count++;
            }
            else {
                int ind = m[s[i]];
                if(ind < startInd) {
                    m[s[i]] = i;
                    count++;
                }
                else {
                    count -= (ind - startInd);
                    startInd = ind + 1;
                    m[s[i]] = i;
                }
            }
            maxLen = max(maxLen, count);
        }
        
        return maxLen;
    }
};