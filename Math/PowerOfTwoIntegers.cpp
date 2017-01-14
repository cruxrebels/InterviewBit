bool Solution::isPower(int A) {
    if (A < 2)
        return true;
    vector<int> factors;
    for (auto i = 2; i*i <= A; ++i)
        if (A % i == 0)
            for (auto k = 2; k <= 32; ++k) // since 32 bit signed num can contain atmost x^32 range in
                if (pow(i, k) == A)       // base x number system
                    return true;
    return false;
}
