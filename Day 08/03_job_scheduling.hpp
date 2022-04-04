/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    static bool compare(Job j1, Job j2) {
        if(j1.profit > j2.profit) return true;
        else if(j1.profit == j2.profit) return j1.dead < j2.dead;
        return false;
    }
    
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr + n, this->compare);
        
        vector<bool> slots(n, false);
        int jobs = 0, profit = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=min(n, arr[i].dead)-1; j>=0; j--) {
                if(slots[j] == false) {
                    jobs++;
                    profit += arr[i].profit;
                    slots[j] = true;
                    break;
                }
            }
        }
        
        vector<int> ans;
        ans.push_back(jobs);
        ans.push_back(profit);
        
        return ans;
    } 
};