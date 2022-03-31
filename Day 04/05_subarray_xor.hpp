int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int, int> m;
    m[0] = 1;

    int count = 0, tmpXor = 0;
    for(int i=0; i<n; i++) {
        tmpXor = tmpXor ^ A[i];
        int Xor6 = tmpXor ^ B;
        if(m.count(Xor6) > 0) count += m[Xor6];
        m[tmpXor]++;
    }

    return count;
}
