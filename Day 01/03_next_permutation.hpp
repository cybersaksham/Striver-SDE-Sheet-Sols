class Solution {
public:
    void swapInds(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int peekInd = n - 1;
        while(peekInd > 0) {
            if(nums[peekInd] <= nums[peekInd - 1]) peekInd--;
            else break;
        }
        
        int i = peekInd;
        int j = n - 1;
        while(i < j) this->swapInds(nums, i++, j--);
        
        if(peekInd == 0) return;
        
        int peekPos = peekInd - 1;
        for(int i=peekInd; i<n; i++) {
            if(nums[i] > nums[peekPos]) {
                this->swapInds(nums, peekPos, i);
                break;
            }
        }
    }
};