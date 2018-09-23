/*
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach’s conjecture

Example:


Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d. 

https://www.interviewbit.com/problems/prime-sum/
*/

// Solution 1 - Simple and without extra space
bool isPrime(int A) {
    for (auto i = 2; i*i <= A; ++i)
        if (A%i == 0)
            return false;
    return true;
}

vector<int> Solution::primesum(int A) {
    vector<int> res;
    if (A%2 != 0)
        return res;
    
    for (auto j = 2; j <= A/2; ++j) {
        auto diff = A-j;
        if (isPrime(j) && isPrime(diff)) {
            res.emplace_back(j);
            res.emplace_back(diff);
            break;
        }
    }
    return res;
}

// Solution 2 - Uses extra space with arr showing whether prime or not
bool isPrime(int n)
{
    for(int i=2; i*i<=n; ++i)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

vector<int> Solution::primesum(int A) {
    vector<int> result;
    if(A<3)
        return result;
    vector<bool> arr(A+1, 0); //vector<int> causes judge memory overflow.
    
    for (int i=2; i<=A; ++i)
    {
        if(arr[i]==0)
        {
            if(isPrime(A-i))
            {
                result.emplace_back(i);
                result.emplace_back(A-i);
                break;
            }
            for(int j=i; i*j<=A; ++j)
                arr[i*j] = 1;
        }   
    }
    return result;
}

// Solution 3 - Uses extra space and complex write up
void findPrimes(vector<int>* result, int A)
{
    vector<bool> temp(A+1, true);
    temp[0] = temp[1] = false;
    for (auto i = 2; i*i<=A; ++i)
    {
        for (auto j = i*2; j<=A; j += i)
            temp[j] = false;
    }
    for (auto k = 2; k<A+1; ++k)
    {
        if (temp[k] && temp[A-k])
        {
            (*result).emplace_back(k);
            (*result).emplace_back(A-k);
            break;
        }
    }
}

vector<int> Solution::primesum(int A) {
    if (A % 2 != 0)
        return {};
    vector<int> result;
    //vector<int> primes;
    findPrimes(&result, A);
    /*for(auto i = 0; i<primes.size(); ++i) 
    {
        const auto& it = find_if(primes.cbegin(), primes.cend(), [&primes, &i, &A] (const int& prime)
        {
            return A - primes[i] == prime;
        });
        if (it != primes.cend())
        {
            result.emplace_back(primes[i]);
            result.emplace_back(*it);
            break;
        }
    }*/
    return result;
}
