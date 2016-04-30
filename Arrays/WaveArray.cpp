vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(), A.end());
    int s = A.size();
    int i = 0;
    while (i<=s-2)
    {
        swap(A[i], A[i+1]);
        i += 2;
    }
    return A;
}
