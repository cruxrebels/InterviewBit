vector<int> Solution::allFactors(int A) {
    vector<int> result;
 
    for(auto i=1; i<=sqrt(A); ++i)
    {
        if(A%i==0)
        {
            result.emplace_back(i);
            if(i!=sqrt(A))
            {
                result.emplace_back(A/i);
            }
        }
    }
    sort(result.begin(), result.end());
    return result;
}
