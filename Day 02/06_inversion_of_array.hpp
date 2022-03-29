long long merge(long long *arr, int low, int mid, int high) {
    long long inversions = 0;    
    long long *arr1 = new long long[high - low + 1];
    int i = low, j = mid + 1, k = 0;
    
    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j]) arr1[k++] = arr[i++];
        else {
            arr1[k++] = arr[j++];
            inversions += (mid - i + 1);
        }
    }    
    while(i <= mid) arr1[k++] = arr[i++];
    while(j <= high) arr1[k++] = arr[j++];
    
    for(int p=0; p<high-low+1; p++) arr[p + low] = arr1[p];
    
    return inversions;
}

long long mergeSort(long long *arr, int low, int high) {
    long long inversions = 0;
    if(low < high) {
        int mid = low + (high - low) / 2;
        inversions += mergeSort(arr, low, mid);
        inversions += mergeSort(arr, mid + 1, high);
        inversions += merge(arr, low, mid, high);
    }
    return inversions;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergeSort(arr, 0, n - 1);
}