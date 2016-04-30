int Solution::gcd(int A, int B) {
    //Euclid's algorithm
    while(B!=0)
    {
        int r = A%B;
        A = B;
        B = r;
    }
    return A;
}

//Recursive one line solution
/*int Solution::gcd(int A, int B) {
    //Euclid's algorithm
    return B==0 ? A : gcd(B, A%B);
}*/
