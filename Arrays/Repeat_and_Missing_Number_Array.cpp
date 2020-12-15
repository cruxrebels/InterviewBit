/*There are certain problems which are asked in the interview to also check how you take care of overflows in your problem.
This is one of those problems.
Please take extra care to make sure that you are type-casting your ints to long properly and at all places. Try to verify if your solution works if number of elements is as large as 105

    Food for thought :

        "Even though it might not be required in this problem, in some cases, you might be required to order the operations cleverly so that the numbers do not overflow.
        For example, if you need to calculate n! / k! where n! is factorial(n), one approach is to calculate factorial(n), factorial(k) and then divide them.
        Another approach is to only multiple numbers from k + 1 ... n to calculate the result.
        Obviously approach 1 is more susceptible to overflows."

You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4

https://www.interviewbit.com/problems/repeat-and-missing-number-array/

*/


vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n =A.size();
    long long int sq1=0,sum1=0,sum2=0,sq2=0,x,a;
    vector <int> v(2,0);
    int i;
    for(i=0;i<n;i++){
        sum2=sum2+long(i+1);
        sq2=sq2+long(i+1)*long(i+1);
        sum1=sum1+long(A[i]);
        sq1=sq1+long(A[i])*long(A[i]);
    }
    
    x=(sq1-sq2)/(sum1-sum2);
    a=(x+(sum1-sum2))/2;
    v[0]=a;
    v[1]=x-a;
    return v;
}
