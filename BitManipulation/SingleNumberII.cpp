/*
Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?

Example :

Input : [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Output : 4

https://www.interviewbit.com/problems/single-number-ii/
*/

int Solution::singleNumber(const vector<int> &A) {
    int result = 0;
    for (auto i=0; i<32; ++i) //works for any occurence of number but only on 32 bit system
    {
        int sum = 0;
        for (auto j=0; j<A.size(); ++j)
        {
            if ((A[j] >> i) & 1 == 1)
            {
                ++sum;
                sum %= 3;
            }
        }
        if (sum!=0)
            result |= sum << i;
    }
    return result;
    /*int t1 = 0, t2 = 0, t3 = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        t1 ^= A[i];
        t2 = t2 | ((t1^A[i]) & A[i]);
        t3 = ~(t1 & t2);
        t1 = t1 & t3;
        t2 = t2 & t3;
    }
    return t1;*/
}
