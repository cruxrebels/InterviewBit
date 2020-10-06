/*
Problem Description

Given a number A. Find the fatorial of the number.

Problem Constraints
1 <= A <= 100

Input Format
First and only argument is the integer A.

Output Format
Return a string, the factorial of A.

Example Input
Input 1:

A = 2
Input 2:

A = 3

Example Output
Output 1:
 2
Output 2:
 6

Example Explanation
Explanation 1:

2! = 2 .
Explanation 2:

3! = 6 .

https://www.interviewbit.com/problems/large-factorial/
*/

// Approach A - Since BigInteger wasn't self imported.
public class Solution {
    public int multiply(int num, int list[], int size) {
        int carry = 0;
        for (int i = 0; i < size; ++i) {
            int product = (num*list[i]) + carry;
            list[i] = product%10;
            carry = product/10;
        }
        while (carry != 0) {
            list[size] = carry%10;
            carry = carry/10;
            ++size;
        }
        return size;
    }
    
    public String solve(int A) {
        int[] result = new int[500];
        result[0] = 1;
        String res = "";
        int size = 1;
        
        for (int i = A; i > 1; --i) {
            size = multiply(i, result, size);
        }
        
        for (int i = size-1; i > -1; --i)
            res += result[i];
        return res;
    }
}

---
// Approach B - Brute force import BigInteger.
import java.math.BigInteger;

public String solve(int A) {
        BigInteger res = BigInteger.ONE;
        
        for (int i = A; i > 1; --i) {
            res = res.multiply(new BigInteger(String.valueOf(i)));
        }
        return String.valueOf(res);
    }
}
