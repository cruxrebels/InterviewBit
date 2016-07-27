/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. 
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2

https://www.interviewbit.com/problems/2-sum/
*/

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    vector<int> res;
    auto size = A.size();
    unordered_map<int, int> hash;
    
    for (auto i = 0; i<size; ++i)
    {
        if (hash.find(B - A[i]) != hash.end())
        {
            res.emplace_back(hash[B - A[i]]);
            res.emplace_back(i+1);
            return res;
        }
        if (hash.find(A[i]) == hash.end())
            hash[A[i]] = i+1;
    }
    
    return res;
}
