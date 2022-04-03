class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<pair<int, int>> maxHT(n);
        int maxh = 0;
        for(int i=0; i<n; i++) {
            maxHT[i].first = maxh;
            maxh = max(maxh, height[i]);
        }
        maxh = 0;
        for(int i=n-1; i>=0; i--) {
            maxHT[i].second = maxh;
            maxh = max(maxh, height[i]);
        }
        
        int count = 0;
        for(int i=0; i<n; i++) {
            if(min(maxHT[i].first, maxHT[i].second) > height[i]) count += (min(maxHT[i].first, maxHT[i].second) - height[i]);
        }
        
        return count;
    }
};