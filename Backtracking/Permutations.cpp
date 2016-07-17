/*
Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]
 NOTE
No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.
Example : next_permutations in C++ / itertools.permutations in python.
If you do, we will disqualify your submission retroactively and give you penalty points.

https://www.interviewbit.com/problems/permutations/
*/

void backtracking(vector<vector<int> >& res, vector<int>& A)
{
    int size = A.size();
    int k = -1;
    for (auto i = 0; i<size-1; ++i)
    {
        if(A[i]<A[i+1])
            k = i;
    }
    
    if (k==-1)
        return;
    int l;
    for (auto j = k+1; j<size; ++j)
    {
        if (A[j]>A[k])
            l = j;
    }
    
    int temp = A[k];
    A[k] = A[l];
    A[l] = temp;
    
    reverse(A.begin() + k + 1, A.end());
    res.emplace_back(A);
    backtracking(res, A);
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > res;
    sort(A.begin(), A.end()); //special case e.g. A = 3,2,1.
    res.emplace_back(A);
    backtracking(res, A);
    
    //check result
    int n = A.size();
    int f = 1;
    for (auto e = 2; e<n+1; ++e)
        f *= e;
    int resSize = res.size();
    if (resSize == f)
        return res;
}
