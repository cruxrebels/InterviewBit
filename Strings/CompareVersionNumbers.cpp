/*
Compare two version numbers version1 and version2.

If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 1.13 < 1.13.4

https://www.interviewbit.com/problems/compare-version-numbers/
*/

void delLeadingZeroes(string& X, int len)
{
    for (auto k=0; k<len; ++k)
    {
        int temp = X[k] - '0';
        if (!temp)
            X.erase(0, 1);
        else
            break;
    }
}

int isGreater(string A, string B)
{
    auto as = A.length(), bs = B.length();
    int lenGap = as - bs;
    if(lenGap!=0)
        return lenGap>0 ? 1 : -1;
    else if (A != B)
        return A>B ? 1 : -1;
    else
        return 0;
}

void splitString(string& str, vector<string>& s)
{
    size_t pos = 0;
    while ((pos = str.find(".")) != std::string::npos)
    {
        string token = str.substr(0, pos);
        s.push_back(token);
        str.erase(0, pos+1);
    }
}

int Solution::compareVersion(string A, string B) {
    int i = 0, j = 0;
    vector<string> a, b;
    
    splitString(A, a);
    splitString(B, b);
    a.push_back(A); //for the last part of A & also if A didn't had any dots
    b.push_back(B); //for the last part of B & also if B didn't had any dots
    
    int is = a.size(), js = b.size();
    while (i<is && j<js)
    {
        delLeadingZeroes(a[i], a[i].length());
        delLeadingZeroes(b[j], b[j].length());
        auto temp = isGreater(a[i], b[j]);
        
        if (temp!=0)
            return temp;
        else
        {
            ++i; ++j;
            if (i==is && j<js)
            {
                delLeadingZeroes(b[j], b[j].length());
                if (b[j]!="")
                    return -1;
            }
            else if (i<is && j==js)
            {
                delLeadingZeroes(a[i], a[i].length());
                if(a[i]!="")
                    return 1;
            }
        }
    }
    return 0;
}
