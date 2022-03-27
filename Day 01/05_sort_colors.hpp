class Solution {
public:
    void swapInds(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid = 0;
        
        while(mid <= high) {
            if(nums[mid] == 0) this->swapInds(nums, low++, mid++);
            else if(nums[mid] == 1) mid++;
            else this->swapInds(nums, mid, high--);
        }
    }
};