/*
Reverse bits of an 32 bit unsigned integer

Example 1:

x = 0,

          00000000000000000000000000000000  
=>        00000000000000000000000000000000
return 0

Example 2:

x = 3,

          00000000000000000000000000000011 
=>        11000000000000000000000000000000
return 3221225472

https://www.interviewbit.com/problems/reverse-bits/
*/

unsigned int Solution::reverse(unsigned int A) {
    unsigned int numOfBits = sizeof(A)*8;   //Simple bitwise approach
    unsigned int result = 0;
    
    for (auto i = 0; i<numOfBits; ++i)
    {
        if ((A>>i) & 1 == 1)
            result |= 1 << ((numOfBits-1) - i);
    }   
    return result;
    /*int i = 31;               //Bits Math Logic approach
    unsigned int result = 0;
    while (i>-1)
    {
        if (A%2==1)
            result += pow(2, i);
        --i; 
        A /= 2;
    }
    return result;*/
}
