/*
For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1

https://www.interviewbit.com/problems/colorful-number/
*/

int Solution::colorful(int A) {
    vector<int> vec;
    while (A != 0) {
        vec.emplace_back(A%10);
        A /= 10;
    }
    reverse(vec.begin(), vec.end());
    unordered_map<long long, bool> hash;
    for (auto i = 0; i < vec.size(); ++i) {
        long long value = 1;
        for (auto j = i; j < vec.size(); ++j) {
            value *= vec[j];
            if (hash.find(value) != hash.end())
                return 0;
            hash.insert({value, true});
        }
    }
    return 1;
}
