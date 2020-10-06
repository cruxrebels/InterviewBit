/*
Problem Description

Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array.

Find and return the required subarray.

NOTE:

If there is a tie, then compare with segment's length and return segment which has maximum length.
If there is still a tie, then return the segment with minimum starting index.


Problem Constraints
1 <= N <= 105
-109 <= A[i] <= 109



Input Format
The first and the only argument of input contains an integer array A, of length N.



Output Format
Return an array of integers, that is a subarray of A that satisfies the given conditions.



Example Input
Input 1:

 A = [1, 2, 5, -7, 2, 3]
Input 2:

 A = [10, -1, 2, 3, -4, 100]


Example Output
Output 1:

 [1, 2, 5]
Output 2:

 [100]


Example Explanation
Explanation 1:

 The two sub-arrays are [1, 2, 5] [2, 3].
 The answer is [1, 2, 5] as its sum is larger than [2, 3].
Explanation 2:

 The three sub-arrays are [10], [2, 3], [100].
 The answer is [100] as its sum is larger than the other two.
 
https://www.interviewbit.com/problems/max-non-negative-subarray/
*/

public class Solution {
    public ArrayList<Integer> maxset(ArrayList<Integer> A) {
        if (A.isEmpty()) 
            return A;
        
        // Approach A - cleaner and straightforward solution following the problem conditions.
        long maxSum = 0, newSum = 0;
        ArrayList<Integer> maxArray = new ArrayList();
        ArrayList<Integer> newArray = new ArrayList();
        
        for (Integer i : A) {
            if (i >= 0) {
                newSum += i;
                newArray.add(i);
            } else {
                newSum = 0;
                newArray = new ArrayList();
            }
            if (newSum > maxSum || (maxSum == newSum && newArray.size() > maxArray.size())) {
                maxSum = newSum;
                maxArray = newArray;
            }
        }
        return maxArray;
        
        // Approach B - Messy with brute force handling of multiple edge cases
        /*long sum = 0, maxSum = -1;
        int iter = 0, start = 0, end = 0;
        int tempStart = 0, neg = 0;
        boolean first = false;
        A.add(-1); // to force updation of maxSum at line 14 after input array end
        while (iter < A.size()) {
            if (A.get(iter) < 0) {
                ++neg;
                if (sum > maxSum) {
                    maxSum = sum;
                    start = tempStart;
                    end = iter - 1;
                }
                sum = 0;
                first = true;
                ++iter;
                continue;
            }
            if (sum == 0 && first) {
                first = false;
                tempStart = iter;
            }
            sum += A.get(iter);
            ++iter;
        }
        
        ArrayList<Integer> result;
        if (neg == A.size())
            result = new ArrayList();
        else
            result = new ArrayList(A.subList(start, end+1));  
        return result;*/
    }
}
