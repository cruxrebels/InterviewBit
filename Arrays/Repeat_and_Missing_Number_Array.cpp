vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n =A.size();
    long long int sq1=0,sum1=0,sum2=0,sq2=0,x,a;
    vector <int> v(2,0);
    int i;
    for(i=0;i<n;i++){
        sum2=sum2+long(i+1);
        sq2=sq2+long(i+1)*long(i+1);
        sum1=sum1+long(A[i]);
        sq1=sq1+long(A[i])*long(A[i]);
    }
    
    x=(sq1-sq2)/(sum1-sum2);
    a=(x+(sum1-sum2))/2;
    v[0]=a;
    v[1]=x-a;
    return v;
}
