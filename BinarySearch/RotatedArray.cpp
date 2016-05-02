/*
Suppose a sorted array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array will not contain duplicates.

NOTE 1: Also think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*
PROBLEM APPROACH:

Note: If you know the number of times the array is rotated, then this problem becomes trivial. If the number of rotation is x, then minimum element is A[x].
Lets look at how we can calculate the number of times the array is rotated.

https://www.interviewbit.com/problems/rotated-array/
*/

int Solution::findMin(const vector<int> &A) {
    int n = A.size();
    int low = 0, high = n-1;
    
    while(low<=high)
    {
        if (A[low]<=A[high]) return A[low];
        
        int mid = low + (high-low)/2;
        int next = (mid+1)%n, prev = (n + mid - 1)%n;
        
        if (A[mid]<=A[next] && A[mid]<=A[prev]) return A[mid];
        else if (A[mid]<=A[high]) high = mid - 1;
        else if (A[low]<=A[mid])  low = mid + 1;
    }
    return -1;
}
