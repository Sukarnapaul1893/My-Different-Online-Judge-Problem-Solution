#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int M = 1000003;

LL power(LL a, LL p) {
    if (p == 0) return 1;
    LL ans = power(a, p/2);
    ans = (ans * ans)%M;
    if (p%2)    ans = (ans*a)%M;
    return ans;
}

#define N 1000001
//unordered_map<int,LL>fac,invfac,p2;
LL fac[N], invfac[N], p2[N];
void pre() {
    fac[0] = 1;
    for(int i=1; i<N; i++)  fac[i] = (i*fac[i-1])%M;
    invfac[N-1] = power(fac[N-1], M-2);
    for (int i=N-2; i>=0; i--)  invfac[i] = (invfac[i+1]*(i+1))%M;
}

LL C(int n, int r) {
    if (r<0 || r>n) return 0;
    LL denom = (invfac[r]*invfac[n-r])%M;
    return (fac[n]*denom)%M;
}
int main(){
    //ax + by = __gcd(a,b);
    int t;
    scanf("%d",&t);
    pre();
    for(int tt=0;tt<t;tt++){
        int n,k;
        scanf("%d %d",&n,&k);
        printf("Case %d: %d\n",tt+1,C(n,k));
    }
}
