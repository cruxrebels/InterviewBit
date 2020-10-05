/*
Predict the output of the following program :

vector<int> performOps(vector<int> A) {
    vector<int> B(2 * A.size(), 0);
    for (int i = 0; i < A.size(); i++) {
        B[i] = A[i];
        B[i + A.size()] = A[(A.size() - i) % A.size()];
    }
    return B;
}

Lets say performOps was called with A : [5, 10, 2, 1]. What would be the output of the following call :


vector<int> B = performOps(A);
for (int i = 0; i < B.size(); i++) {
    cout<<B[i]<<" ";
}

https://www.interviewbit.com/problems/arrayimpl1/
*/

5 10 2 1 5 1 2 10
