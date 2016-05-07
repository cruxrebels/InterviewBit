/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).

You are given a target value to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Input : [4 5 6 7 0 1 2] and target = 4
Output : 0

NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*

https://www.interviewbit.com/problems/rotated-sorted-array-search/
*/

int search2(const vector<int> &A, int l, int h, int key)
{
    if (l > h) return -1;
 
    int mid = (l+h)/2;
    if (A[mid] == key) return mid;
 
    /* If arr[l...mid] is sorted */
    if (A[l] <= A[mid])
    {
        /* As this subarray is sorted, we can quickly
           check if key lies in half or other half */
        if (key >= A[l] && key <= A[mid])
           return search2(A, l, mid-1, key);
 
        return search2(A, mid+1, h, key);
    }
 
    /* If arr[l..mid] is not sorted, then arr[mid... r]
       must be sorted*/
    if (key >= A[mid] && key <= A[h])
        return search2(A, mid+1, h, key);
 
    return search2(A, l, mid-1, key);
}
int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    int i = search2(A, 0, n-1, B);
    return i;
}
/*int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    int low = 0, high = n - 1;
    int pivot = -1;
    
    while(low<=high)
    {
        if(A[low]<=A[high])
        {
            pivot = low;
            break;
        }
        int mid = low + (high-low)/2;
        if(A[mid]==B)
            return mid;
            
        int prev = (mid+n-1)%n, next = (mid+1)%n;
        if(A[prev]>=A[mid] && A[next]>=A[mid])
        {
            pivot = mid;
            break;
        }
        else if (A[mid]<=A[high])
            high = mid - 1;
        else if (A[low]<=A[mid])
            low = mid + 1;
    }
    if (pivot != -1)
    {
        vector<int> V;
        for (auto i=0; i<n; ++i)
            V.emplace_back(A[i]);
        std::rotate(V.begin(), V.begin()+pivot, V.end());

        low = 0, high = n - 1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(V[mid]==B)
                return ((mid+pivot)%n);
            else if (V[mid]>B)
                high = mid - 1;
            else 
                low = mid + 1;
        }
    }
    return -1;
}*/
