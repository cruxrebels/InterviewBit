string Solution::findDigitsInBinary(int A) {
    int r;
    string result;
    
    if(A==0)
        return "0"; //prev used result += to_string(0); return result;

    while(A>0)
    {
        r = A%2;
        result += to_string(r); //Or result.push_back((char)('0' + r)); will also work
        A /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
}
