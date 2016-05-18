/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
**Example 2 : **
ABCD, 2 can be written as

A....C
...B....D
and hence the answer would be ACBD.

https://www.interviewbit.com/problems/zigzag-string/
*/

string Solution::convert(string A, int B) {
    if (B<2)
        return A;
    bool flag = false;
    vector<string> zigzag(B, "");
    int i = 0; // for string
    int r = 0; //for row
    while (i<A.length())
    {
        if (r<B && !flag)
        {
            zigzag[r] += A[i]; ++i; ++r;
        }
        else
        {
            if (!flag)
            {
                --r;
                flag = true;
            }
            else
            {
                --r;
                zigzag[r] += A[i];
                ++i;
                if (r==0)
                {
                    flag = false;
                    ++r;
                }
            }
        }
    }
    A.clear();
    for (auto p = 0; p<B; ++p)
        A += zigzag[p];
    return A;
}
