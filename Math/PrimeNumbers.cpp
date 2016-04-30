vector<int> Solution::sieve(int A) {
    vector<int> result;
    
    //First approach
    /*for(auto i = 0; i<=A; ++i)
        result.emplace_back(i);
    result[0] = 0;
    result[1] = 0;
    for(auto j = 2; j*j<=A; ++j) //same as condition j<=sqrt(A)
    {
        if(result[j]!=0)
        {
            for(auto k = j; j*k<=A; ++k)
                result[j*k] = 0;
        }
    }
    result.erase(remove(result.begin(), result.end(), 0), result.end()); //inefficient operation
    return result;*/
    
    //Second approach
    if(A<2)
        return result;
    int arr[A+1];
    memset(arr, 0, sizeof(arr)); //memset converts (int)0 to (unsigned char)0 before writing to arr.
    
    for(auto i = 2; i<=A; ++i)
    {
        if(arr[i]==0)
        {
            result.emplace_back(i);
            for(auto j = i; i*j<=A; ++j) //slightly better than (auto j=i*2; j<=A; j+=i)
                arr[i*j] = 1;
        }
    }
    return result;
}
