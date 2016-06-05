/*
You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

Find i, j, k such that :
max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

**abs(x) is absolute value of x and is implemented in the following manner : **

      if (x < 0) return -x;
      else return x;
Example :

Input : 
        A : [1, 4, 10]
        B : [2, 15, 20]
        C : [10, 12]

Output : 5 
         With 10 from A, 15 from B and 10 from C. 
         
https://www.interviewbit.com/problems/array-3-pointers/
*/

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int result = INT_MAX;
    int temp1, temp2, temp3;
    int i = 0, j = 0, k = 0;
   
    while(i<A.size() && j<B.size() && k<C.size())
    {
        temp1=A[i]-B[j];
        temp2=B[j]-C[k];
        temp3=C[k]-A[i];
        result = min(result, max(abs(temp1), max(abs(temp2), abs(temp3))));
        if(abs(temp1)>=abs(temp2) && abs(temp1)>=abs(temp3))
        {
            if(temp1>0)
                ++j;
            else
                ++i;
        }
        else if(abs(temp2)>=abs(temp1) && abs(temp2)>=abs(temp3))
        {
            if(temp2>0)
                ++k;
            else
                ++j;
        }
        else if(abs(temp3)>=abs(temp1) && abs(temp3)>=abs(temp2))
        {
            if(temp3>0)
                ++i;
            else
                ++k;
        }
    }
    return result;
}
