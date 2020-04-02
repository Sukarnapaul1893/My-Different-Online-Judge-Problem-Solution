//Author : Sukarna Paul

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define pi acos(-1)
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll int64_t
#define MAX 300005
#define INF 0x3f3f3f3f
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}

using namespace std;
using namespace __gnu_pbds;

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

vector<ll>vec;

void pre(){
    ll lim = 1e10;
    ll cur = 1;
    vec.pb(0);
    while(cur*cur<=lim){
        vec.pb(cur*cur);
        cur++;
    }
}

ll arr[100005];

void nodcalc(){
    for(int i=0;i<vec.size();i++){
        vector<ll>primef;

        ll cur = i;

        for(ll p=2;p*p<=i;p++){
            ll cnt=0;
            while(cur%p==0){
                cnt++;
                cur/=p;
            }
            if(cnt>0)primef.pb(cnt*2+1);
        }
        if(cur>1)primef.pb(3);
        arr[i]=1;
        for(int j=0;j<primef.size();j++){
            arr[i]*=primef[j];
        }
        //if(vec[i]!=1)arr[i]++;
    }
}
vector<ll>data[400020];

int query(int at, int L, int R, int l, int r,ll k){
    if(r<L || R<l)return 0;
    if(l<=L && R<=r){
        int cnt = upper_bound(data[at].begin(),data[at].end(),k)-data[at].begin();
        return (data[at].size()-cnt);
    }

    int mid = (L+R)/2;

    int x = query(at*2,L,mid,l,r,k);
    int y = query(at*2+1,mid+1,R,l,r,k);

    return (x+y);
}
void build(int at , int L, int R){
    if(L==R){
        data[at].pb(arr[L]);
        return;
    }
    int mid = (L+R)/2;
    build(at*2,L,mid);
    build(at*2+1,mid+1,R);
    int i,j;
    for(i=0,j=0;i<data[at*2].size() && j<data[at*2+1].size();){
        if(data[at*2][i]<=data[at*2+1][j]){
            data[at].pb(data[at*2][i]);
            i++;
        }
        else{
            data[at].pb(data[at*2+1][j]);
            j++;
        }
    }
    for(;i<data[at*2].size();i++){
        data[at].pb(data[at*2][i]);
    }
    for(;j<data[at*2+1].size();j++){
        data[at].pb(data[at*2+1][j]);
    }

}
int main(){
    IOS
    //freopen("output.txt","w",stdout);
    pre();
    nodcalc();
    /*for(int i=0;i<109;i++){
        cout<<vec[i]<<" "<<arr[i]<<"\n";
    }*/
    int n = vec.size();
    build(1,1,n);
    int t;
    cin>>t;
    for(int tt=0;tt<t;tt++){
        ll k , l,r;
        cin>>k>>l>>r;
        int L = lower_bound(vec.begin(),vec.end(),l)-vec.begin();
        int R = lower_bound(vec.begin(),vec.end(),r)-vec.begin();
        //cout<<vec[L]<<" "<<vec[R]<<"\n";
        //cout<<L<<" "<<R<<"\n";
        if(vec[R]>r)R--;
        if(vec[L]>r || L>R || vec[R]<l){
            cout<<0<<"\n";
            continue;
        }
        int a = query(1,1,n,L,R,k);
        int b = query(1,1,n,L,R,k-1);
        cout<<b-a<<"\n";
    }
}
