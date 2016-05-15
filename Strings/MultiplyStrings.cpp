/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

 Note: The numbers can be arbitrarily large and are non-negative.
Note2: Your answer should not have leading zeroes. For example, 00 is not a valid answer. 
For example, 
given strings "12", "10", your answer should be “120”.

NOTE : DO NOT USE BIG INTEGER LIBRARIES ( WHICH ARE AVAILABLE IN JAVA / PYTHON ). 
We will retroactively disqualify such submissions and the submissions will incur penalties.

https://www.interviewbit.com/problems/multiply-strings/
*/

string Solution::multiply(string A, string B) {
    if (A=="0" || B=="0")
        return "0";
        
    int aL = A.length(), bL = B.length();
    vector<int> result(aL+bL, 0);
    string res = "";
    
    for (auto i=aL-1; i>=0; --i)
    {
        for (auto j=bL-1; j>=0; --j)
        {
            result[i+j+1] += (A[i] - '0')*(B[j] - '0');
        }
    }
    
    for (auto k=aL+bL-1; k>0; --k)
    {
        if (result[k] >= 10)
        {
            result[k-1] += result[k]/10;
            result[k] %= 10;
        }
    }
    
    int cnt = 0;
    for (auto l=0; l<result.size(); ++l)
    {
        if (result[l]==0 && l==cnt) //To omit the leading zeroes E.g. 00456723 will be 456723.
            ++cnt;
        else
            res += result[l] + '0'; //I was doing "-0" it was throwing internal error!
    }
    return res;
}
