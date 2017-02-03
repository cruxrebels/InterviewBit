/*
Find the kth smallest element in an unsorted array of non-negative integers.

Definition of kth smallest element

 kth smallest element is the minimum possible n such that there are at least k elements in the array <= n.
In other words, if the array A was sorted, then A[k - 1] ( k is 1 based, while the arrays are 0 based ) 
NOTE
You are not allowed to modify the array ( The array is read only ). 
Try to do it using constant extra space.

Example:

A : [2 1 4 3 2]
k : 3

answer : 2

https://www.interviewbit.com/problems/kth-smallest-element-in-the-array/
*/

int Solution::kthsmallest(const vector<int> &A, int k) {
    if (k > A.size())
        return -1;
    /*priority_queue<int, vector<int>, greater<int> > Q;
    for (auto i = 0; i<k; ++i)
        Q.push(A[i]);
    for (auto j = k; j<A.size(); ++j)
    {
        if (Q.top() > A[j])
        {
            Q.pop_back();
            Q.push(A[j]);
        }
    }
    
    return Q.top();*/
    
    int lo = *min_element(A.begin(), A.end());
    int hi = *max_element(A.begin(), A.end());
    
    while (lo <= hi)
    {
        int mid = lo + (hi - lo)/2;
        int countLess = 0, countEqual = 0;
        
        for (auto i = 0; i<A.size(); ++i)
        {
            if (A[i]<mid)
                ++countLess;
            else if (A[i] == mid)
                ++countEqual;
            if (countLess >= k)
                break;
        }
        
        if (countLess < k && countLess + countEqual >= k)
            return mid;
        else if (countLess >= k)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return -1;
}
