/*
Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

 Example: Input : 
    A : [1 3 5] 
    k : 4
 Output : YES as 5 - 1 = 4 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Try doing this in less than linear space complexity.

https://www.interviewbit.com/problems/diffk/
*/

int Solution::diffPossible(vector<int> &A, int B) {
   int n=A.size();
   int p=0, q=0;
   while(q<n){
       if(q==p)
            q++;
       else if(A[q]-A[p]==B && q!=p)
        return 1;
       else if(A[q]-A[p]>B)
            p++;
       else if(A[q]-A[p]<B)
            q++;
   }
   return 0;
}
