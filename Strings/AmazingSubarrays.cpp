/*
You are given a string S, and you have to find all the amazing substrings of S.

Amazing Substring is one that starts with a vowel (a, e, i, o, u, A, E, I, O, U).

Input

Only argument given is string S.
Output

Return a single integer X mod 10003, here X is number of Amazing Substrings in given string.
Constraints

1 <= length(S) <= 1e6
S can have special characters
Example

Input
    ABEC

Output
    6

Explanation
	Amazing substrings of given string are :
	1. A
	2. AB
	3. ABE
	4. ABEC
	5. E
	6. EC
	here number of substrings are 6 and 6 % 10003 = 6.

https://www.interviewbit.com/problems/amazing-subarrays/
*/

const int MOD = 10003;
bool isVowel(char A) {
    bool res = true;
    switch (A) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            res = true;
            break;
        default:
            res = false;
            break;
    }
    return res;
}

int Solution::solve(string A) {
    int count = 0;
    size_t N = A.length();
    for (size_t i = 0; i < N; ++i) {
        if (isVowel(A[i])) {
            count += N - i;
        }
    }
    return count%MOD;
}
