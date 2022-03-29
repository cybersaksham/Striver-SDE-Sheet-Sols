vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> v = A;
    sort(v.begin(), v.end());
    vector<int> ans(2);
    for(int i=0; i<v.size()-1; i++) {
        if(v[i] == v[i + 1]) ans[0] = v[i];
        else if(v[i + 1] - v[i] > 1) ans[1] = v[i] + 1;
    }
    if(ans[1] == 0) {
        if(v[v.size() - 1] == v.size()) ans[1] = 1;
        else ans[1] = v.size();
    }

    return ans;
}
