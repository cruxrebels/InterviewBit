/*
Write a function that takes an unsigned integer and returns the number of 1 bits it has.

Example:

The 32-bit integer 11 has binary representation

00000000000000000000000000001011
so the function should return 3.

https://www.interviewbit.com/problems/number-of-1-bits/
*/

int Solution::numSetBits(unsigned int A) {
    int c = 0;
    /*while(A)  //Simple O(log n) approach
    {
        if (A & 1)
            ++c;
        A >>= 1;
    }*/
    while(A!=0) //Brian Kernighan’s Algorithm: iterates only over set bits
    {
        A &= A-1;
        ++c;
    }
    return c;
}
