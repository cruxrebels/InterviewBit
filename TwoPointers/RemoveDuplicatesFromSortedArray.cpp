/*
Remove duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.

Note that even though we want you to return the new length, make sure to change the original array as well in place

Do not allocate extra space for another array, you must do this in place with constant memory.

 Example: 
Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2]. 

https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/
*/

int Solution::removeDuplicates(vector<int> &A) {
    int i = 0;
    int n = A.size();
    while (i<A.size()-1)
    {
        int j = i+1;
        if(A[i]==A[j])
        {
            while(A[i]==A[j] && j<A.size())
                ++j;
            --j; n -= (j-i);
            A.erase(A.begin()+i+1, A.begin()+j+1);
        }
        ++i;
    }
    return n;
}
