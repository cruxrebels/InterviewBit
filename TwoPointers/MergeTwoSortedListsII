/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

 Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
TIP: C users, please malloc the result into a new array and return the result. 
If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n

Example :

Input : 
         A : [1 5 8]
         B : [6 9]

Modified A : [1 5 6 8 9]

https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/
*/

void Solution::merge(vector<int> &A, vector<int> &B) {
    int n = B.size();
    int p = 0, q = 0;
    
    while(p<A.size() && q<n)
    {
        if(A[p]<B[q])
        {
            ++p;
        }
        else if(A[p]>=B[q])
        {
            A.insert(A.begin()+p, B[q]);
            ++q; ++p;
        }
    }
    while(q<n)
    {
        A.push_back(B[q]);
        ++q;
    }
}
