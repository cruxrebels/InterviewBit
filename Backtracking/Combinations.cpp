/*
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,
1. Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
2. Entries should be sorted within themselves.

Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 
See Expected Output

https://www.interviewbit.com/problems/combinations/
*/

void backtracking(int start, int k, vector<vector<int> >& result, vector<int>& A, vector<int>& row)
{
    auto size = A.size();
    if (row.size() == k)
    {
        result.emplace_back(row);
        return;
    }
    if (start >= size)
        return;
    
    row.emplace_back(A[start]);
    backtracking(start+1, k, result, A, row);
    row.pop_back();
    backtracking(start+1, k, result, A, row);
}

vector<vector<int> > Solution::combine(int n, int k) {
    vector<vector<int> > result;
    vector<int> A;
    for (auto i = 1; i<n+1; ++i)
        A.emplace_back(i);
    vector<int> row;
    backtracking(0, k, result, A, row);
    return result;
}
