/*
Find if Given number is power of 2 or not. 
More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:

number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:

return 1 if the number if a power of 2 else return 0

Example:

Input : 128
Output : 1

https://www.interviewbit.com/problems/power-of-2/
*/

/*int Solution::power(string A) { //Tried Binary search but it's not applicable for inputs of 2^64 size
    if (A=="0" || A=="1")         //since temp = stoi(A) will fail for very large inputs.
        return 0;
    if (A=="2")
        return 1;
    __int128 temp = stoi(A);    //Tried using __int128 for inputs 2^64 ranges; compiled successfully.
    __int128 start = 0, end = temp;
    while (start<=end)
    {
        __int128 mid = start + (end-start)/2;
        
        if(mid==temp/mid)
            return 1;
        else if(mid < temp/mid)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return 0;
}*/
bool Not_one(string N) { //Checks if N is equal to 1 or not
    int sz = N.size();
    if(sz > 1)
            return 1;
    if(N[0] != '1')
            return 1;
    return 0;
}

bool is_Eve(string N) { //Checks if N is even or not
    int data = (N[N.size() - 1] - '0') & 1; //Bitwise AND operation 0 1 0 1 //binary for 5; N[index]
    if(data)                                //Binary for 6          0 1 1 0         & 1; 0 0 0 1
         return 0;                          //                      -------
    return 1;                               //Yields result:        0 1 0 0 //binary for 4 
}

string Divide(string N, int data) { //Divides the string by 2
    reverse(N.begin(), N.end());
    long long base = 10;
    string temp = "";
    for(int i = (int)N.size() - 1, rem = 0; i >= 0; --i) {
        long long Cur = (N[i] - '0') + rem * base;
        int val = Cur / data;
        rem = Cur % data;
        temp += (val + '0');
    }
    
    while(temp.size() && !(temp[0] - '0')) //Suppose temp = 00033; so temp is returned and assigned to N
            temp.erase(temp.begin());      //which is again sent to Divide(N,2) so now after reverse
                                           ///N = 33000 where this zeroes can be avaoided from computation.
    return temp;
}

int Solution::power(string N) {
    int sz = N.size();
    if(sz == 1) {
        if(N[0] == '2' || N[0] == '4' || N[0] == '8')
                return 1;
        return 0;
    } else {
        while(Not_one(N) && is_Eve(N)) {
            N = Divide(N, 2);
            if(N.size() == 1 &&  N[0] == '1')
                    break;
        }
        if(Not_one(N))
                return 0;
        return 1;
    }
}
