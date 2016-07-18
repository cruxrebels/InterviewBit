/*
Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]

https://www.interviewbit.com/problems/subset/
*/

void backtracking(int start, vector<vector<int> >& result, vector<int>& A, vector<int>& row)
{
    int size = A.size();
    if (start >= size)
    {
        result.emplace_back(row);
        return;
    }
    
    backtracking(start+1, result, A, row);
    
    row.emplace_back(A[start]);
    backtracking(start+1, result, A, row);
    row.pop_back();
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int> > result;
    sort(A.begin(), A.end());
    vector<int> row;
    backtracking(0, result, A, row);
    sort(result.begin(), result.end());
    return result;
}
