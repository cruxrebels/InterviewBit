/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    
https://www.interviewbit.com/problems/excel-column-title/
*/

char numToAlpha(int i) {
    return i + 'A' - 1;
}

string Solution::convertToTitle(int A) {
    int rem = 0;
    string res = "";
    while(A != 0) {
        rem = A%26;
        if (!rem) {     // if rem = 0, to understand this dry run with A = 52 (AZ)
            rem = 26;   // implies it ticked over 26, but value should be 'Z'
            A -= 26;    // the next value has an addendum of 26 which gives 'B'Z
        }               // which should have given 'A'Z, so reducing 26 corrects the offset.
        res += numToAlpha(rem);
        A /= 26;
    }
    reverse(res.begin(), res.end());
    return res;
}
