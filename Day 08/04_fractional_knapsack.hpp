/*
struct Item{
    int value;
    int weight;
};
*/


class Solution {
    static bool compareFunc(Item i1, Item i2) {
        double a = (double)i1.value / (double)i1.weight;
        double b = (double)i2.value / (double)i2.weight;
        return a > b;
    }
    
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) {
        // Your code here
        sort(arr, arr + n, this->compareFunc);
        double count = 0;
        int i = 0;
        while(W > 0) {
            if(i < n) {
                if(arr[i].weight <= W) {
                    count += (double)arr[i].value;
                    W -= arr[i].weight;
                }
                else {
                    count += (double)(W * (double)((double)arr[i].value / (double)arr[i].weight));
                    W = 0;
                    break;
                }
            }
            else break;
            i++;
        }
        return count;
    }
};