//Author : Sukarna Paul
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
unordered_map<ll,ll>dp;
long long binpow(long long a, long long b, long long m) {
    if(dp[b]!=0)return dp[b];
    if(b==0)return 1;
    if(b&1LL){
        ll res = binpow(a,b/2,m);
        dp[b]= res*res*a;
        dp[b]%=m;
        return dp[b];
    }
    else{
        ll res = binpow(a,b/2,m);
        dp[b]= res*res;
        dp[b]%=m;
        return dp[b];
    }
}
int main(){
    IOS
    int t;
    cin>>t;

    for(int tt=0;tt<t;tt++){
        ll n;
        cin>>n;
        if(n==1 || n==2){
            cout<<n<<"\n";
            continue;
        }
        if(n%3==0){
            cout<<binpow(3LL,n/3LL,1000000007LL)<<"\n";
        }
        else if(n%3==1){
            ll res = binpow(3LL,(n-4)/3LL,1000000007LL);
            res*=4;
            res%=1000000007LL;
            cout<<res<<"\n";
        }
        else if(n%3==2){
            ll res = binpow(3LL,(n-2)/3,1000000007LL);
            res*=2;
            res%=1000000007LL;
            cout<<res<<"\n";
        }

    }
}
