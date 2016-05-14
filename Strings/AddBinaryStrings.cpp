/*
Given two binary strings, return their sum (also a binary string).

Example:

a = "100"

b = "11"
Return a + b = “111”.

https://www.interviewbit.com/problems/add-binary-strings/
*/

/*int stringToInt(string lit) //Naive approach, fails for very large inputs
{
    auto result = 0;
    reverse(lit.begin(), lit.end());
    //cout << lit << endl;
    for (auto i = 0; i<lit.length(); ++i)
    {
        if (result+(lit[i] - '0')*pow(2, i) < INT_MAX)
            result += (lit[i] - '0')*pow(2, i);
        //cout << result << " "; 
    }
    return result;
}
string decToBinary(int dec)
{
    string result = "";
    while(dec!=0)
    {
        int rem = dec%2;
        result += to_string(rem);
        dec /= 2;
    }
    return result;
}
string Solution::addBinary(string A, string B) {
    auto a = stringToInt(A);
    auto b = stringToInt(B);
    cout << a << " " << b << endl;
    auto intResult = a + b;
    cout << intResult;
    auto strResult = decToBinary(intResult);
    reverse(strResult.begin(), strResult.end());
    
    return strResult;
}*/
string Solution::addBinary(string A, string B) {
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    auto aS = A.length(), bS = B.length();
    int n = aS>=bS ? aS : bS;
    int c = 0;
    string result = "";
    for (auto i = 0; i<n; ++i)
    {
        int a = i < aS ? A[i] - '0' : 0;
        int b = i < bS ? B[i] - '0' : 0;
        int temp = a + b + c;
        c = temp / 2;
        result += to_string(temp%2);
    }
    if (c==1)
        result += to_string(c);
    reverse(result.begin(), result.end());
    return result;
}
