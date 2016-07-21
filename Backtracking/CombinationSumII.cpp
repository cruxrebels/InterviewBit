/*
e integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example :

Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 

https://www.interviewbit.com/problems/combination-sum-ii/
*/

void backtracking(int start, vector<int>& row, int sum, vector<vector<int> >& res, vector<int>& A, int B)
{
    if (sum==B)
    {
        /*vector<int> lastRow;              // Simple layman approach to avoid repeated subsets.
        if (!res.empty())                   // Uncomment this block and code will still work.
            lastRow = res[res.size()-1];
        if (res.empty() || lastRow != row)*/
            res.emplace_back(row);
        return;
    }
    
    if (sum > B || start == A.size())
        return;
        
    row.emplace_back(A[start]);
    sum += A[start];
    backtracking(start+1, row, sum, res, A, B);
    sum -= row[row.size()-1];
    row.pop_back();
    
    int endIndex = 0;                       // Refined memory saving way to avoid repeated subsets.
    for (endIndex = start+1; endIndex < A.size() && A[endIndex]==A[start]; ++endIndex)
        ++start;
        
    backtracking(start+1, row, sum, res, A, B); // endIndex = start+1; so passing endIndex will also work.
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int> > res;
    vector<int> row;
    sort(A.begin(), A.end());
    backtracking(0, row, 0, res, A, B);
    return res;
}
