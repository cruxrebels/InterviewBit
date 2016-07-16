/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
There might be multiple gray code sequences possible for a given n.
Return any such sequence.

https://www.interviewbit.com/problems/gray-code/
*/

int binaryToGray(int num)
{
    return num ^ (num >> 1);
}
vector<int> Solution::grayCode(int A) {
    vector<int> res;
    for (auto i = 0; i<pow(2, A); ++i)
        res.emplace_back(binaryToGray(i));
    return res;
}
