/*
Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

Note that even though we want you to return the new length, make sure to change the original array as well in place

For example,
Given input array A = [1,1,1,2],

Your function should return length = 3, and A is now [1,1,2].

https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/
*/

int Solution::removeDuplicates(vector<int> &A) {
    /*int i = 0;            // Erasing approach
    int len = A.size();
    while (i<A.size())
    {
        int j = i+1;
        if(A[i]==A[j])
        {
            ++j;
            while(A[i]==A[j] && j<len)
                ++j;
            --j; len -= (j-1-i);
            A.erase(A.begin()+i+1, A.begin()+j);
        }
        ++i;
    }
    return len;*/
    int count = 0;          // Just moving duplicates at back of vector approach, faster;
    int size = A.size();
    for(auto i = 0; i<size; ++i)
    {
        if(i<size-2 && A[i]==A[i+1] && A[i]==A[i+2]) continue;
        else
            A[count++] = A[i];
    }
    return count;
}
