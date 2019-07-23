vector<string> Solution::fullJustify(vector<string> &A, int B) {
    vector<string> result;
    short int k = 0, ls = 0;
    for (short int i = 0; i<A.size(); i+=k)
    {
        
        k = ls = 0;
        while (i+k<A.size() && ls + k + A[i+k].size() <= B)
        {
            ls += A[i+k].size();
            ++k;
        }
        string tmp = A[i];
        for (int j = 0; j < k - 1; j++) {
            if (i + k >= A.size()) tmp += " ";
            else tmp += string((B - ls) / (k - 1) + (j < (B - ls) % (k - 1)), ' ');
            tmp += A[i+j+1];
        }
        tmp += string(B - tmp.size(), ' ');
        
        
        result.emplace_back(tmp);
    }
    return result;
}
