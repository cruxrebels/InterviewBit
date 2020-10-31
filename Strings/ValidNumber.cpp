/*
Please Note:

Note: It is intended for some problems to be ambiguous. You should gather all requirements up front before implementing one.

Please think of all the corner cases and clarifications yourself.

Validate if a given string is numeric.

Examples:

"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Clarify the question using “See Expected Output”

Is 1u ( which may be a representation for unsigned integers valid?
For this problem, no.
Is 0.1e10 valid?
Yes
-01.1e-10?
Yes
Hexadecimal numbers like 0xFF?
Not for the purpose of this problem
3. (. not followed by a digit)?
No
Can exponent have decimal numbers? 3e0.1?
Not for this problem.
Is 1f ( floating point number with f as prefix ) valid?
Not for this problem.
How about 1000LL or 1000L ( C++ representation for long and long long numbers )?
Not for this problem.
How about integers preceded by 00 or 0? like 008?
Yes for this problem

https://www.interviewbit.com/problems/valid-number/
*/

int Solution::isNumber(const string A) {

    int i = 0;
    int len = A.length();
    int flag = 0;
    while (A[i] == ' ' && i < len)
        i++;

    while (i < len) {
        flag = 1;
        if ((A[i] >= '0' && A[i] <= '9') || (A[i] == '.') || (A[i] == '-' && i == 0) || (A[i] == ' '))
            i++;
        else if (A[i] == 'e' && A[i - 1] != '.') {
            i++;
            while (A[i] != '.' && i < len)
                i++;
            if (i != len)
                return 0;
        } else
            return 0;
    }

    if (A[i - 1] != '.' && flag)
        return 1;
    return 0;
}
