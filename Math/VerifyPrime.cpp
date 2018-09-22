/*
Given a number N, verify if N is prime or not.

Return 1 if N is prime, else return 0.

Example :

Input : 7
Output : True

https://www.interviewbit.com/problems/verify-prime/
*/

int Solution::isPrime(int A) {
    if (A<2)
        return 0;
    for(auto i=2; i<=sqrt(A); ++i)
    {
        if(A%i==0)
            return 0;
    }
    return 1;
}
