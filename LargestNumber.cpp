bool myCompare(const int x, const int y)
{
    int tempx = x;
    int tempy = y;
    int cx = 0;
    int cy = 0;
    while(tempx!=0 || tempy!=0)
    {
        if(tempx!=0)
        {
            tempx /= 10;
            ++cx;
        }
        if(tempy!=0)
        {
            tempy /= 10;
            ++cy;
        }
    }
    int xy = (x*(pow(10, cy)))+y;
    int yx = (y*(pow(10, cx)))+x;
    //cout << xy << "\t" << yx << "\t" << x << "\t" << y << "\n";
    return (xy>yx);
}

string Solution::largestNumber(const vector<int> &A) {
    vector<int> B;
    int c = 0;
    stringstream r;
    r << 0;
    for(auto const& a : A)
    {
        B.emplace_back(a);
        if (a==0)
            ++c;
    }
    if (c==A.size())
        return r.str();
        
    sort(B.begin(), B.end(), myCompare);
    
    string result = "";
    for(const auto& b : B)
        result+=to_string(b);
        
    //copy(B.begin(), B.end(), ostream_iterator<int>(result, ""));
    return result;
}
