/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]

https://www.interviewbit.com/problems/subsets-ii/
*/

void backtracking(int start, vector<vector<int> >& result, vector<int>& A, vector<int>& row)
{
    int size = A.size();
    if (start>=size)
    {
        /*auto s = result.size();   //Valid, but got TLE for this.
        if (s==0)
            result.emplace_back(row);
        else
        {
            while(s>0)
            {
                vector<int> temp = result[s-1];
                --s;
                if (temp == row)
                    return;
            }
            result.emplace_back(row);
        }
        return;*/
        result.emplace_back(row);
        return;
    }
    
    auto currIndex = start + 1;
    while (currIndex<A.size() && A[currIndex]==A[start])
        ++currIndex;
        
    for (auto i = 0; i<=currIndex-start; ++i)
    {
        for (auto j = 0; j<i; ++j)
            row.emplace_back(A[start]);
        backtracking(currIndex, result, A, row);
        for (auto j = 0; j<i; ++j)
            row.pop_back();
    }
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    vector<vector<int> > result;
    vector<int> row;
    sort(A.begin(), A.end());
    backtracking(0, result, A, row);
    sort(result.begin(), result.end());
    return result;
}
