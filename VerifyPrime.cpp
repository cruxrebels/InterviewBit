int Solution::isPrime(int A) {
    if (A<2)
        return 0;
    for(auto i=2; i<=sqrt(A); ++i)
    {
        if(A%i==0)
            return 0;
    }
    return 1;
}
