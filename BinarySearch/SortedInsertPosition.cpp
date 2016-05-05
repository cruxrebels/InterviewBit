/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.

[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

https://www.interviewbit.com/problems/sorted-insert-position/
*/

int Solution::searchInsert(vector<int> &A, int B) {
    if(B<1)
        return 0;
    int start = 0, end = A.size() - 1;
    int pos = -1;
    
    while(start<=end)
    {
        int mid = start + (end - start)/2;
        if(A[mid] == B)
            return mid;
        else if(A[mid]>B)
            pos = end = mid - 1;
        else
            pos = start = mid + 1;
        if (start>end)
            pos = start;
    }
    return pos;
}
