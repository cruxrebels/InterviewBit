/*
Predict the output of the following program :

vector<vector<int> > performOps(vector<vector<int> > &A) {
    vector<vector<int> > B;
    B.resize(A.size());
    for (int i = 0; i < A.size(); i++) {
        B[i].resize(A[i].size());
        for (int j = 0; j < A[i].size(); j++) {
            B[i][A[i].size() - 1 - j] = A[i][j];
        }
    }
    return B;
}

Lets say performOps was called with A : [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]] .

What would be the output of the following call :


vector<vector<int> > B = performOps(A);
for (int i = 0; i < B.size(); i++) {
    for (int j = 0; j < B[i].size(); j++) cout<<B[i][j]<<" ";
}

https://www.interviewbit.com/problems/array2d/
*/

4 3 2 1 8 7 6 5 12 11 10 9
