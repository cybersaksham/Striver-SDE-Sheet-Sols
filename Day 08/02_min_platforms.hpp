class Solution{
    static int convertIntoMinutes(int n) {
        int *ans = new int[4];
        for(int i=0; i<4; i++) {
            ans[i] = n % 10;
            n /= 10;
        }
        
        int a = ans[2] + (ans[3] * 10);
        int b = ans[0] + (ans[1] * 10);
        
        delete[] ans;
        return a * 60 + b;
    }
    
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
    	// Your code here
    	vector<pair<int, int>> v(n);
    	for(int i=0; i<n; i++) v[i] = {this->convertIntoMinutes(arr[i]), this->convertIntoMinutes(dep[i]) + 1};
    	
    	vector<int> timeGraph(24 * 60 + 1, 0);
    	for(int i=0; i<n; i++) {
    	    timeGraph[v[i].first] += 1;
    	    timeGraph[v[i].second] -= 1;
    	}
    	
    	int platforms = 0, tmpPlatforms = 0;
    	for(int i=0; i<timeGraph.size(); i++) {
    	    tmpPlatforms += timeGraph[i];
    	    platforms = max(platforms, tmpPlatforms);
    	}
    	
    	return platforms;
    }
};