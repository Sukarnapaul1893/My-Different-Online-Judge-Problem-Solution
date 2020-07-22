#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
ll L,R;
void input();
vector <ll> prime;
bitset <10000010> bs;

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

ll CountFor1ToN(ll N){
    ll cnt = 0;
    for(int i=0;i<prime.size() && prime[i]*prime[i]<=N;i++){
        ll p = prime[i]*prime[i];
        for(int j=2;p<=N;j++){
            if(!bs[j+1]){
                p*=prime[i];
                continue;
            }
            cnt++;

            p*=prime[i];
        }
    }

    return cnt;
}

void solve(){
    ll ansL=CountFor1ToN(L-1);
    ll ansR=CountFor1ToN(R);

    cout<<(R+1-L)-(ansR-ansL)<<"\n";
}

void Clear(){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve(1000000);
    input();
    solve();
    Clear();
}

void input(){
    cin>>L>>R;
}
