class Solution {
    static bool binarySearch(vector<int> &arr, int target, int low, int high) {
        if(low > high) return false;
        int mid = low + (high - low) / 2;
        
        if(target < arr[mid]) return binarySearch(arr, target, low, mid - 1);
        else if(target > arr[mid]) return binarySearch(arr, target, mid + 1, high);
        else return true;
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool found = false;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0; i<m; i++) {
            if(target >= matrix[i][0] && target <= matrix[i][n - 1]) {
                return this->binarySearch(matrix[i], target, 0, n - 1);
            }
        }
        
        return false;
    }
};