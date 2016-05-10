/*
The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.

https://www.interviewbit.com/problems/count-and-say/
*/
string Solution::countAndSay(int A) {
    string result = "";
    
    if(!A)
        return result;
    
    string str = "1";
    int cnt = 1;
    
    for (int i = 1; i<A; ++i)
    {
        int len = str.length();
        for(int j = 0; j<len; ++j)
        {
            if (j+1 != len && str[j]==str[j+1])
            {
                ++cnt; 
            }
            else
            {
                result += to_string(cnt) + str[j];
                cnt = 1;
            }
        }
        str = result;
        result.clear();
    }
    return str;
}
