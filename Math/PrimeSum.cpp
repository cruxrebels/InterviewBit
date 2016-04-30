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
            //prime.emplace_back(i);
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
