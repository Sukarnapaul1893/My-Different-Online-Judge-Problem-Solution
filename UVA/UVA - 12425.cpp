#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
ll n,q;

//returns the number of coprimes less than x
ll phi(ll x) {
    ll ans = x;

    for (ll i=2; i*i <= x; i++) {
        if (x%i)    continue;
        while (x%i==0)  x/=i;
        ans = (ans/i)*(i-1);
    }

    if (x > 1)  ans = (ans/x)*(x-1);
    return ans;
}

void input();

vector<pair<ll,int> >queries;
vector<ll>divisors;
vector<pair<ll,ll > >allPhi;

void SortQueries(){
    sort(queries.begin(),queries.end());
}
ll ans[50004];
void PrintQueries(){
    for(int i=0;i<q;i++)cout<<ans[i]<<"\n";
}

void FindDivisors(){
    ll sq = sqrt(n+1);
    for(ll i=1;i<=sq;i++){
        if(n%i!=0)continue;
        divisors.pb(i);
        ll div = n/i;
        if(i!=div)divisors.pb(div);
    }
}

void FindPhi(){
    sort(divisors.begin(),divisors.end());
    for(int i=0;i<divisors.size();i++){
        ll div = divisors[i];
        ll p = phi(n/div);
        allPhi.pb({div,p});
    }
}

void TwoPointer(){
    ll sum = 0;

    for(int i=0,j=0;i<q;){
        if(j>=allPhi.size()){
            int idx=queries[i].second;
            ans[idx]=sum;
            i++;
        }
        else if(allPhi[j].first>queries[i].first){
            int idx=queries[i].second;
            ans[idx]=sum;
            i++;
        }
        else{
            sum+=allPhi[j].second;
            j++;
        }
    }
}

void solve(){
    SortQueries();

    FindDivisors();

    FindPhi();

    TwoPointer();

    PrintQueries();
}

void Clear(){
    queries.clear();
    divisors.clear();
    allPhi.clear();
    for(int i=0;i<q;i++)ans[i]=0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<"\n";
        input();
        solve();
        Clear();
    }
}

void input(){
    cin>>n;
    cin>>q;
    for(int i=0;i<q;i++){
        ll x;
        cin>>x;
        queries.pb({x,i});
    }
}
