// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])
int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int count = 0;
    int a = 0; int b = 0;
    for (int i=0; i < (X.size()-1); ++i) {
        a = abs((X[i+1]-X[i]));
        b = abs((Y[i+1]-Y[i]));
        count += max(a,b);
    }
    return count;
}
