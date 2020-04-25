//Author : Sukarna Paul

#include<bits/stdc++.h>
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

#define ff first
#define ss second
#define mp make_pair
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;

const PLL M=mp(1e9+7, 1e9+9);   ///Should be large primes
const LL base=347;              ///Should be a prime larger than highest value
const int N = 1e3+7;            ///Highest length of string

ostream& operator<<(ostream& os, PLL hash) {
    return os<<"("<<hash.ff<<", "<<hash.ss<<")";
}

PLL operator+ (PLL a, LL x)     {return mp(a.ff + x, a.ss + x);}
PLL operator- (PLL a, LL x)     {return mp(a.ff - x, a.ss - x);}
PLL operator* (PLL a, LL x)     {return mp(a.ff * x, a.ss * x);}
PLL operator+ (PLL a, PLL x)    {return mp(a.ff + x.ff, a.ss + x.ss);}
PLL operator- (PLL a, PLL x)    {return mp(a.ff - x.ff, a.ss - x.ss);}
PLL operator* (PLL a, PLL x)    {return mp(a.ff * x.ff, a.ss * x.ss);}
PLL operator% (PLL a, PLL m)    {return mp(a.ff % m.ff, a.ss % m.ss);}

PLL power (PLL a, LL p) {
    if (p==0)   return mp(1,1);
    PLL ans = power(a, p/2);
    ans = (ans * ans)%M;
    if (p%2)    ans = (ans*a)%M;
    return ans;
}

///Magic!!!!!!!
PLL inverse(PLL a)  {
    return power(a, (M.ff-1)*(M.ss-1)-1);
}

PLL pb[N];      ///powers of base mod M
PLL invb;

///Call pre before everything
void hashPre() {
    pb[0] = mp(1,1);
    for (int i=1; i<N; i++)
        pb[i] = (pb[i-1] * base)%M;
    invb = inverse(pb[1]);
}

///Calculates Hash of a string
PLL Hash (string s) {
    PLL ans = mp(0,0);
    for (int i=0; i<s.size(); i++)
        ans=(ans*base + s[i])%M;
    return ans;
}
vector<PLL> hashList(string s) {
    int n = s.size();
    vector<PLL> ans(n+1);
    ans[0] = mp(0,0);

    for (int i=1; i<=n; i++)
        ans[i] = (ans[i-1] * base + s[i-1])%M;
    return ans;
}

///Calculates hash of substring s[l..r] (1 indexed)
PLL substringHash(const vector<PLL> &hashlist, int l, int r) {
    int len = (r-l+1);
    return ((hashlist[r] - hashlist[l-1]*pb[len])%M+M)%M;
}



int main(){
    IOS
    //freopen("output.txt","w",stdout);
    hashPre();
    int t;
    cin>>t;

    for(int tt=0;tt<t;tt++){
        int n,m;
        cin>>n>>m;
        string t[n];
        for(int i=0;i<n;i++)cin>>t[i];

        int x,y;
        cin>>x>>y;
        string s[x];
        for(int i=0;i<x;i++)cin>>s[i];

        vector<PLL> ht[n];

        for(int i=0;i<n;i++){
            ht[i] = hashList(t[i]);
        }

        PLL Hs[x];
        for(int i=0;i<x;i++)Hs[i]=Hash(s[i]);

        int cnt = 0;
        for(int i=0;i<=n-x;i++){

            for(int j=0;j<=m-y;j++){

                bool bl=true;
                int cur =0;
                for(int k=i;k<i+x;k++){
                    if(substringHash(ht[k],j+1,j+y)!=Hs[cur++]){bl=false;break;}
                }
                if(bl)cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
}
