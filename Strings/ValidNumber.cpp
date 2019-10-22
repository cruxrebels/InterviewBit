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

int Solution::isNumber(const string &A) {
    int i = 0;
    int n = A.length();
    while (A[i]==' ') { ++i; }
    if(i==n)
        return 0;
        
    if ((A[i]=='-' || A[i]=='+') && ((A[i+1]>='0' && A[i+1]<='9') || A[i+1]=='.'))
        i+=2;
    else if (A[i]=='e')
        return 0;
    
    bool eflag = false, dflag = false;
    
    while (i<n)
    {
        if(A[i]=='.')
        {
            if(eflag || dflag)
                return 0;
            else if(A[i+1]>='0' && A[i+1]<='9')
                i+=2;
            else
                return 0;
            dflag = true;
        }
        else if (A[i]=='e')
        {
            if(eflag)
                return 0;
            eflag = true;
            if ((A[i+1]=='-' || A[i+1]=='+') && (A[i+2]>='0' && A[i+2]<='9'))
                i+=3;
            else if (A[i+1]>='0' && A[i+1]<='9')
                i+=2;
            else
                return 0;
        }
        else if (A[i]>='0' && A[i]<='9')
            ++i;
        else if (A[i]==' ')
        {
            ++i;
            while (A[i]==' ') { ++i; }
            if(i==n)
                return 1;
        }
        else
            return 0;
    }
    return 1;
}
