class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int ptr = prices[0];
        
        for(int i=0; i<prices.size(); i++) {
            if(prices[i] > ptr) profit = max(profit, prices[i] - ptr);
            else ptr = prices[i];
        }
        
        return profit;
    }
};