class Solution
{
    static bool compareInterval(pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    }
    
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n) {
        // Your code here
        if(n <= 0) return 0;
        
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++) v.push_back({start[i], end[i]});
        sort(v.begin(), v.end(), this->compareInterval);
        
        int meetings = 1;
        int timeVar = v[0].second;
        for(int i=1; i<n; i++) {
            if(v[i].first > timeVar) {
                meetings++;
                timeVar = v[i].second;
            }
        }
        
        return meetings;
    }
};