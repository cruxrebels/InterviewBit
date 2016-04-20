int Solution::firstMissingPositive(vector<int> &A) {
    sort(A.begin(), A.end());
    int c = 1;
    for (auto const& a : A)
    {
        if (a<1)
            continue;
        else if (a==c)
        {
            ++c;
            continue;
        }
        else
            break;
    }
    return c;
}
