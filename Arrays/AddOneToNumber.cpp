/*
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

 NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

https://www.interviewbit.com/problems/add-one-to-number/
*/

vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> result;
    if (A.empty())
        return result;
    
    int z = 0; int size = A.size();
    while (z < size && A[z] == 0)
        ++z;
    if (z == size)
        return vector<int> {1};
    
    int carry = 0;
    for (int end = size-1; end>=z; --end)
    {
        if (end == size-1 && A[end] != 9)
        {
            ++A[end]; 
            break;
        }
        
        if (A[end] == 9)
        {
            A[end] = 0;
            carry = 1;
        }
        else
        {
            ++A[end]; 
            carry = 0; 
            break;
        }
    }
    
    if (carry)
    {
        result.emplace_back(carry);
        vector<int> temp(A.cbegin() + z, A.cend());
        for (auto& t : temp)
            result.emplace_back(t);
    }
    else
        result = vector<int>(A.cbegin() + z, A.cend());
    return result;
}
