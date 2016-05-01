/*
Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer

https://www.interviewbit.com/problems/reverse-integer/
*/

int Solution::reverse(int A) {
    bool flag = false;
    if(A<0)
    {
        A *= -1;
        flag = true;
    }
    int sum = 0;

    while(A!=0)
    {
        int rem = A%10;
        if (sum > INT_MAX/10 || sum == INT_MAX/10 && rem > INT_MAX%10)
            return 0;
        sum = sum*10 + rem;
        A /= 10;
    }
    
    if(flag)
        sum *= -1;
    return sum;
}
