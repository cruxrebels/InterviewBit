/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example :

Input : [1 2 2 3 1]
Output : 3
See Expected Output

https://www.interviewbit.com/problems/single-number/
*/

int Solution::singleNumber(const vector<int> &A) {
    /*int temp = 0;                 //standard approach
    for (auto i=0; i<A.size(); ++i)
        temp ^= A[i];
    return temp;*/
    
    return accumulate(A.begin(), A.end(), 0, bit_xor<int>()); //std library method
}
