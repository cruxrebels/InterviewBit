int Solution::titleToNumber(string A) {
     auto n = A.length();
     int value = 0;
     for (auto i=0; i<n; ++i)
     {
        value += pow(26, i)*(A[n-(i+1)] - 'A' + 1);
     }
     return value;
}
