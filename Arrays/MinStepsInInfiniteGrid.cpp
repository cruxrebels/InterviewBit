// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])

// Slightly verbose version
/*int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int count = 0;
    int a = 0; int b = 0;
    for (int i=0; i < (X.size()-1); ++i) {
        a = abs((X[i+1]-X[i]));
        b = abs((Y[i+1]-Y[i]));
        count += max(a,b);
    }
    return count;
}*/

// Shorter solution
int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    size_t sz = A.size();   // Not comparing the sizes of A & B since 'Expected output' shows this as an invalid test case.
    int steps = 0;
    for (size_t i = 0; i < sz - 1; ++i)
        steps += max(abs(A[i] - A[i+1]), abs(B[i] - B[i+1]));
    return steps;
}
