//Author : Sukarna Paul

#include<bits/stdc++.h>
#define pb push_back
#define ll long long

template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}

using namespace std;

ll mod= 1e9+7;

vector <ll> prime;
bitset <1000010> bs;

void sieve (int n){
	bs.set ();
    //prime.pb(2);
	for (int i = 2; i <= n; i++){
		if (bs[i])prime.pb(i);

		for (int j = 0; j<prime.size() && i*prime[j]<=n; j++){
		    bs[i*prime[j]] = 0;
		    if(i%prime[j]==0)break;
		}
	}
}
vector<pair<ll,ll> >primediv;


ll SOD(){
    ll ans=1;
    for(int i=0;i<primediv.size();i++){

        ll p  = primediv[i].first;
        ll a = primediv[i].second;
        ans = (ans*(bigmod(p,a+1LL,mod)-1LL+mod))%mod;
        ans = (ans*modinverse(p-1LL,mod))%mod;
    }
    return ans;
}

int main(){

    sieve(1000005);
    int t;
    scanf("%d",&t);

    for(int tt=0;tt<t;tt++){
        ll n,m;
        scanf("%lld %lld",&n,&m);
        if(m==0){
            printf("Case %d: %d\n",tt+1,1);
            continue;
        }

        ll cur = n;

        for(int i=0; prime[i]*prime[i]<=cur;i++){
            ll cnt=0;
            while(cur%prime[i]==0){
                cur/=prime[i];
                cnt++;
            }
            if(cnt>0)primediv.pb({prime[i],cnt*m});
        }
        if(cur>1)primediv.pb({cur,m});
        ll ans = SOD();
        primediv.clear();
        printf("Case %d: %lld\n",tt+1,ans);
    }
}
