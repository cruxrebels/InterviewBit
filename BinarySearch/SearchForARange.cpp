/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm’s runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example:

Given [5, 7, 7, 8, 8, 10]

and target value 8,

return [3, 4].

https://www.interviewbit.com/problems/search-for-a-range/
*/

int Pos(const vector<int> &A, int B, bool flag)
{
    int start = 0, end = A.size()-1;
    int result = -1;
    while (start<=end)
    {
        int mid = start + (end - start)/2;
        if(A[mid]==B)
        {
            result = mid;
            if(flag)
                end = mid - 1;
            else
                start = mid + 1;
        }
        else if(A[mid]<B) start = mid + 1;
        else end = mid - 1;
    }
    return result;
}
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    vector<int> result;
    result.emplace_back(Pos(A, B, true));
    result.emplace_back(Pos(A, B, false));
    return result;
}
